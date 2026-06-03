#!/usr/bin/env python3
"""
Send custom telemetry to ThingsBoard for dashboard testing (no ESP32 needed).

Setup:
  pip install paho-mqtt
  copy config.example.py -> config.py  (paste access token)

Examples:
  python thingsboard_test_sender.py --seed-ai          # MQTT, one-shot AI seed
  python thingsboard_test_sender.py --mode rich        # MQTT stream (default)
  python thingsboard_test_sender.py --once '{"temperature": 25, "humidity": 58}'
"""

from __future__ import annotations

import argparse
import json
import math
import random
import re
import sys
import time
import urllib.error
import urllib.request

try:
    import paho.mqtt.client as mqtt
except ImportError:
    print("Install: pip install paho-mqtt")
    sys.exit(1)

try:
    from config import BROKER, MQTT_QOS, PORT, THINGSBOARD_TOKEN, TOPIC
except ImportError:
    BROKER = "mqtt.thingsboard.cloud"
    PORT = 1883
    TOPIC = "v1/devices/me/telemetry"
    MQTT_QOS = 1
    THINGSBOARD_TOKEN = ""


# One-shot payload with varied IoT key names/types — use before "Generate dashboard with AI"
AI_SEED_TELEMETRY = {
    "temperature": 24.5,
    "humidity": 58.0,
    "counter": 40,
    "pressure": 1013.2,
    "co2": 420,
    "battery": 87,
    "rssi": -62,
    "light": 1,
    "motion": 0,
    "status": 1,
}

DEMO_ONCE_TELEMETRY = {"temperature": 25, "humidity": 58, "counter": 40}


def parse_payload(raw: str) -> dict:
    """Parse JSON from CLI; fix PowerShell mangling (unquoted keys)."""
    s = raw.strip()
    attempts = [
        s,
        s.replace("'", '"'),
    ]
    loose = re.sub(r"(\{|,)\s*(\w+)\s*:", r'\1"\2":', s.replace("'", '"'))
    attempts.append(loose)
    for candidate in attempts:
        try:
            data = json.loads(candidate)
            if isinstance(data, dict):
                return data
        except json.JSONDecodeError:
            continue
    raise json.JSONDecodeError(
        "Could not parse JSON. PowerShell: python thingsboard_test_sender.py --demo-once",
        raw,
        0,
    )


def publish_http(token: str, data: dict, host: str = "https://thingsboard.cloud") -> None:
    url = f"{host}/api/v1/{token}/telemetry"
    body = json.dumps(data).encode("utf-8")
    req = urllib.request.Request(
        url,
        data=body,
        headers={"Content-Type": "application/json"},
        method="POST",
    )
    try:
        with urllib.request.urlopen(req, timeout=15) as resp:
            print(f"HTTP {resp.status} →", json.dumps(data))
    except urllib.error.HTTPError as e:
        print(f"HTTP error {e.code}:", e.read().decode("utf-8", errors="replace"))
        sys.exit(1)


def connect_client(token: str, broker: str, port: int) -> mqtt.Client:
    client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2, client_id="ege322_dashboard_test")
    client.username_pw_set(username=token, password="")
    client.connect(broker, port, keepalive=60)
    client.loop_start()
    return client


def publish(client: mqtt.Client, topic: str, data: dict, qos: int = 1) -> None:
    payload = json.dumps(data)
    info = client.publish(topic, payload, qos=qos)
    info.wait_for_publish()
    print("MQTT ->", payload)


def mode_demo(interval: float) -> None:
    counter = 0
    while True:
        if counter > 100:
            counter = 0
        yield {"counter": counter}
        counter += 10
        time.sleep(interval)


def mode_sine(interval: float, keys: list[str]) -> None:
    t = 0.0
    while True:
        data = {}
        for i, key in enumerate(keys):
            # Staggered waves so charts look interesting
            data[key] = round(50 + 40 * math.sin(t + i * 1.2), 2)
        yield data
        t += 0.35
        time.sleep(interval)


def mode_random(interval: float, keys: list[str]) -> None:
    while True:
        data = {key: round(random.uniform(0, 100), 2) for key in keys}
        yield data
        time.sleep(interval)


def mode_rich(interval: float) -> None:
    """Multi-key payload — good for testing several widgets at once."""
    counter = 0
    while True:
        if counter > 100:
            counter = 0
        yield {
            "counter": counter,
            "temperature": round(22 + 8 * math.sin(counter / 15), 1),
            "humidity": round(55 + 20 * math.cos(counter / 20), 1),
            "status": 1 if counter % 20 == 0 else 0,
        }
        counter += 10
        time.sleep(interval)


def run_stream(client: mqtt.Client, topic: str, stream, qos: int) -> None:
    try:
        for data in stream:
            publish(client, topic, data, qos=qos)
    except KeyboardInterrupt:
        print("\nStopped.")


def run_interactive(client: mqtt.Client, topic: str, qos: int) -> None:
    print("Interactive mode — enter JSON objects (empty line to quit).")
    print('Example: {"counter": 42, "temperature": 25.5}')
    while True:
        try:
            line = input("json> ").strip()
        except (EOFError, KeyboardInterrupt):
            print()
            break
        if not line:
            break
        try:
            data = json.loads(line)
        except json.JSONDecodeError as e:
            print("Invalid JSON:", e)
            continue
        if not isinstance(data, dict):
            print("Send a JSON object, e.g. {\"counter\": 1}")
            continue
        publish(client, topic, data, qos=qos)


def main() -> None:
    parser = argparse.ArgumentParser(description="ThingsBoard MQTT test sender")
    parser.add_argument("--token", help="Device access token (overrides config.py)")
    parser.add_argument("--broker", default=None)
    parser.add_argument("--port", type=int, default=None)
    parser.add_argument("--topic", default=None)
    parser.add_argument(
        "--mode",
        choices=["demo", "sine", "random", "rich"],
        default="rich",
        help="demo=assignment counter; rich=multi-key; sine/random=chart testing",
    )
    parser.add_argument("--interval", type=float, default=2.0, help="Seconds between messages")
    parser.add_argument("--keys", default="counter,temperature,humidity", help="Keys for sine/random")
    parser.add_argument("--once", metavar="JSON", help='Single publish, e.g. {"counter": 99}')
    parser.add_argument(
        "--demo-once",
        action="store_true",
        help="Publish {temperature:25, humidity:58, counter:40} — no JSON quoting needed",
    )
    parser.add_argument("--interactive", action="store_true", help="Type custom JSON each line")
    parser.add_argument("--qos", type=int, default=None, help="MQTT QoS (default 1, matches mosquitto_pub -q 1)")
    parser.add_argument("--http", action="store_true", help="Use HTTP API instead of MQTT (default is MQTT)")
    parser.add_argument(
        "--seed-ai",
        action="store_true",
        help="Send AI_SEED_TELEMETRY once (multi-key sample for AI dashboard generation)",
    )
    args = parser.parse_args()

    broker = args.broker or BROKER
    port = args.port if args.port is not None else PORT
    topic = args.topic or TOPIC
    qos = args.qos if args.qos is not None else MQTT_QOS
    token = args.token or THINGSBOARD_TOKEN
    if not token or token.startswith("PASTE_"):
        print("Set THINGSBOARD_TOKEN in config.py or pass --token")
        sys.exit(1)

    if args.seed_ai:
        payload = AI_SEED_TELEMETRY
        if args.http:
            publish_http(token, payload)
        else:
            client = connect_client(token, broker, port)
            try:
                publish(client, topic, payload, qos=qos)
            finally:
                client.loop_stop()
                client.disconnect()
        print("Open device → Generate dashboard with AI")
        return

    if args.http:
        if args.demo_once:
            publish_http(token, DEMO_ONCE_TELEMETRY)
            return
        if args.once:
            publish_http(token, parse_payload(args.once))
            return
        if args.interactive:
            print("HTTP interactive — JSON objects, empty line to quit.")
            while True:
                line = input("json> ").strip()
                if not line:
                    break
                publish_http(token, json.loads(line))
            return
        # stream over HTTP
        keys = [k.strip() for k in args.keys.split(",") if k.strip()]
        streams = {
            "demo": mode_demo(args.interval),
            "sine": mode_sine(args.interval, keys),
            "random": mode_random(args.interval, keys),
            "rich": mode_rich(args.interval),
        }
        try:
            for data in streams[args.mode]:
                publish_http(token, data)
        except KeyboardInterrupt:
            print("\nStopped.")
        return

    print(f"Connecting to {broker}:{port} (MQTT QoS {qos}) …")
    client = connect_client(token, broker, port)
    print("Connected. Publishing to", topic)
    print("(same as: mosquitto_pub -h", broker, "-p", port, "-t", topic, "-u <token> -q", qos, "-m '<json>')")

    try:
        if args.demo_once:
            publish(client, topic, DEMO_ONCE_TELEMETRY, qos=qos)
            return

        if args.once:
            data = parse_payload(args.once)
            publish(client, topic, data, qos=qos)
            return

        if args.interactive:
            run_interactive(client, topic, qos)
            return

        keys = [k.strip() for k in args.keys.split(",") if k.strip()]
        streams = {
            "demo": mode_demo(args.interval),
            "sine": mode_sine(args.interval, keys),
            "random": mode_random(args.interval, keys),
            "rich": mode_rich(args.interval),
        }
        run_stream(client, topic, streams[args.mode], qos)
    finally:
        client.loop_stop()
        client.disconnect()


if __name__ == "__main__":
    main()
