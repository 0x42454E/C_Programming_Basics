import socket

from scapy.layers.l2 import *
from scapy.layers.inet import *

def all_scan(host, port_num):
    """Scan host devices for a specific port"""

    for dev in range(0, 256):
        try:
            #Establish a TCP  connection to the device on the specified port
            subnet = f"{host}.{dev}"
            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            result = sock.connect_ex((subnet, port))
            if result == 0:
                print(f"IP device 192.168.1.{dev} in port {port}: OPEN")
            sock.close()
        except socket.error:
            pass

port = 22
all_scan("10.10.1", port)

