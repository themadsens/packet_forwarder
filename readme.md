	 / _____)             _              | |    
	( (____  _____ ____ _| |_ _____  ____| |__  
	 \____ \| ___ |    (_   _) ___ |/ ___)  _ \ 
	 _____) ) ____| | | || |_| ____( (___| | | |
	(______/|_____)_|_|_| \__)_____)\____)_| |_|
	  (C)2013 Semtech-Cycleo

Lora network packet forwarder project
======================================

1. Core program: basic_pkt_fwd
-------------------------------

The basic packet forwarder is a program running on the host of a Lora Gateway 
that forward RF packets receive by the concentrator to a server through a 
IP/UDP link, and emits RF packets that are sent by the server.

	((( Y )))
	    |
	    |
	+- -|- - - - - - - - - - - - -+        xxxxxxxxxxxx          +--------+
	|+--+-----------+     +------+|       xx x  x     xxx        |        |
	||              |     |      ||      xx  Internet  xx        |        |
	|| Concentrator |<----+ Host |<------xx     or    xx-------->|        |
	||              | SPI |      ||      xx  Intranet  xx        | Server |
	|+--------------+     +------+|       xxxx   x   xxxx        |        |
	|                             |           xxxxxxxx           |        |
	|            Gateway          |                              |        |
	+- - - - - - - - - - - - - - -+                              +--------+

Uplink: radio packets received by the gateway, with metadata added by the
gateway, forwarded to the server. Might also include gateway status.

Downlink: packets generated by the server, with additional metadata, to be
transmitted by the gateway on the radio channel. Might also include
configuration data for the gateway.

2. Derivative: gps_pkt_fwd
-----------------------------------------

This derivative of the basic_packet_forwarder add support for a GPS receiver
for absolute time synchronization and gateway localisation.

3. Helper programs
-------------------

Those programs are included in the project to provide examples on how to 
communicate with the packet forwarder, and to help the system builder use it 
without having to implement a full Lora network server.

### 2.1. util_sink ###

The packet sink is a simple helper program listening on a single port for UDP 
datagrams, and displaying a message each time one is received. The content of 
the datagram itself is ignored.

### 2.2. util_ack ###

The packet acknowledger is a simple helper program listening on a single UDP 
port and responding to PUSH_DATA datagrams with PUSH_ACK, and to PULL_DATA 
datagrams with PULL_ACK.

### 2.3. util_tx_test ###

The network packet sender is a simple helper program used to send packets 
through the gateway-to-server downlink route.

3. Changelog
-------------

v1.2.0 - 2014-02-03

* Feature: added a GPS-enabled packet forwarder, used to timestamp received
packet with a globally-synchronous microsecond-accurate timestamp.
* Feature: GPS packet forwarder sends status report on the uplink, protocol
specification updated accordingly (report include gateway geolocation).
* Feature: packets can be sent without CRC at radio layer.
* Bugfix: no more crash with base64 padded input.
* Bugfix: no more rounding errors on the 'freq' value sent to server.
* A minimum preamble of 6 Lora symbol is enforced for optimum sensitivity.
* Padded Base64 is sent on uplink, downlink accepts padded and unpadded Base64.
* Updated the Parson JSON library to a version that supports comments.
* Added .md (Markdown) extension to readme files for better Github viewing.

v1.1.0 - 2013-12-09

* Feature: added packet filtering parameters to the JSON configuration files.
* Bugfix: won't send a datagram if all the packets returned by the receive()
function have been filtered out.
* Bugfix: removed leading zeros for the timestamp in the upstream JSON because
it's not compliant with JSON standard (might be interpreted as octal number).
* Removed TXT extension for README files for better Github integration.
* Cleaned-up documentation, moving change log to top README.
* Modified Makefiles to ease cross-compilation.

v1.0.0 - 2013-11-22

* Initial release of the packet forwarder, protocol specifications and helper
programs.

4. Legal notice
----------------

The information presented in this project documentation does not form part of 
any quotation or contract, is believed to be accurate and reliable and may be 
changed without notice. No liability will be accepted by the publisher for any 
consequence of its use. Publication thereof does not convey nor imply any 
license under patent or other industrial or intellectual property rights. 
Semtech assumes no responsibility or liability whatsoever for any failure or 
unexpected operation resulting from misuse, neglect improper installation, 
repair or improper handling or unusual physical or electrical stress 
including, but not limited to, exposure to parameters beyond the specified 
maximum ratings or operation outside the specified range. 

SEMTECH PRODUCTS ARE NOT DESIGNED, INTENDED, AUTHORIZED OR WARRANTED TO BE 
SUITABLE FOR USE IN LIFE-SUPPORT APPLICATIONS, DEVICES OR SYSTEMS OR OTHER 
CRITICAL APPLICATIONS. INCLUSION OF SEMTECH PRODUCTS IN SUCH APPLICATIONS IS 
UNDERSTOOD TO BE UNDERTAKEN SOLELY AT THE CUSTOMER�S OWN RISK. Should a 
customer purchase or use Semtech products for any such unauthorized 
application, the customer shall indemnify and hold Semtech and its officers, 
employees, subsidiaries, affiliates, and distributors harmless against all 
claims, costs damages and attorney fees which could arise.