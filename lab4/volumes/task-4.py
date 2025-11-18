#!/usr/bin/env python3

from scapy.all import *


def print_pkt(pkt):
    pkt.show()
    if pkt[ICMP].type == 8 :
        a = IP()
        a.src = pkt[IP].dst
        a.dst = pkt[IP].src
        b = ICMP()
        b.type = 0
        b.id = pkt[ICMP].id
        b.seq = pkt[ICMP].seq
        c = pkt[ICMP].payload

        p = a/b/c
        send(p)



pkt = sniff(iface='br-6d47107d974a', filter='icmp', prn=print_pkt)

