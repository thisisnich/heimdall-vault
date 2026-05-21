
def ledpwm():
    from machine import Pin, PWM
    import time

    led = PWM(Pin(23))
    led.freq(1000)

    while True:
        for duty_cycle in range(0, 1024):
            led.duty(duty_cycle)
            time.sleep_ms(2)

ledpwm()