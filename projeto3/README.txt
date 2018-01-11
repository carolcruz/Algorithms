Telecommunication company Poxim Tech is building a communication system based on the user datagram protocol (UDP) for packet transfer over TCP/IP networks.
	- The data is organized into sequences of bytes of variable size, but limited to the maximum size of 512 bytes;
	- Due to the routing characteristics of TCP / IP networks, the packets can arrive at their destination in a 		  disorderly manner, requiring the ordering of the packets to receive the data correctly;
	- In order to allow rapid access to the data, it is possible to process the received information as long as it is 		  partially ordered with the initial packets, and this processing is triggered by a certain amount of received 		  packets;


INPUT:
	6 2
	0 3 01 02 03
	1 2 04 05
	2 4 06 07 08 09
	4 2 0F 10
	3 5 0A 0B 0C 0D 0E
	5 6 11 12 13 14 15 16

OUTPUT:
	0: 01 02 03 04 05
	1: 06 07 08 09
	2: 0A 0B 0C 0D 0E 0F 10 11 12 13 14 15 16
