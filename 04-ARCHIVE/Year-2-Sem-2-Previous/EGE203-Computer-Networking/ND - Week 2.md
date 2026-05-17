# Networking History
## Standards
### coax
### UTP
#### Types of UTP
- Striaght UTP*
	- PC to hub/switch
	- hub/switch to router
- Crossover UTP*
	- connect same devices
	- hub/switch to hub/switch
- console/rollover UTP
	- PC to switch/router to configure it
\*there is now protocols where devices will "switch" pins so can use straight UTP as a crossover UTP


### Fiber


## OSI
### idk what standard
#### 

## Internet Addressing Scheme
### IP and MAC
- IP is hierarchical and organised -> similar to a postal code
	- numbers, seperated with periods to make easier for human readable
	- used to identify different LANs
- MAC addresses are unique 
	- Non hierarchical and not organized -> similar to NRIC
	- identify specific devices within the same network
	- Embedded on the NIC
### Internet
- what is the internet?
	- interconnected networks
	- each LAN has a unique network address
	- schhols, businesses -> connected together
	- **each network controlled internally**
	- **using routers to connect different LAN's tgt**
#### IP address
- identify where computer and phone is on the internet
	- no IP -> no internet
##### IPv4
- 32 bits -> 4 octets
	- dotted decimal notation
	- e.g. 128.3.2.68
	- 128 - 3 - 2 - 68
	- each octet is one byte 
	- max value of each octet is 255
- first octet



| address class | 1st octet decimal range (first bits) | 1st octet high order bts | Network/Host ID | No. of Networks | Usable Networks |
| ------------- | ------------------------------------ | ------------------------ | --------------- | --------------- | --------------- |
| A             | 1-126*                               | 0                        | N.H.H.H         | 126             | 16,777,214      |
| B             | 128-191                              | 10                       | N.N.H.H         | 16,382          | 65,534          |
| C             | 192-223                              | 110                      | N.N.N.H         | 2,097,150       | 254             |
| D             | 224-239                              | 1110                     | Reserverd       |                 |                 |
| E             | 240-254                              | 11110                    |                 |                 |                 |
\*127 is reserved as loopback address ->  sends back to self

needa memorise 
- A:1-126 -> N.0.0.0
- B:128-191 -> N.N.0.0
- C: 192 - 223 -> N.N.N.0


