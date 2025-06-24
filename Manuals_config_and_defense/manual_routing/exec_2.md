###################################################################################################
###########	# Virtual Network Configuration Without NAT (Bridge Networking Setup)
###########
###########	---
###########
###########	## TAP Device Setup (Host-side)
###########
###########	```bash
###########	# Create a TAP device (a virtual network interface)
###########	sudo ip tuntap add dev tap0 mode tap
###########
###########	#Bring the TAP interface up
########### 	sudo ip link set tap0 up
###################################################################################################

########### No Nat
sudo ip tuntap add dev tap0 mode tap
sudo ip link set tap0 up

qemu-system-x86_64 -m 4G \
-drive file= \
-boot c  \
-netdev tap,id=net0,ifname=tap0,script=no,downscript=no \
-device virtio-net-pci,netdev=net0

sudo ip link set eth0 up


sudo sysctl -w net.ipv4.ip_forward=1

sudo ip link add name br0 type bridge
sudo ip link set dev ens3 master br0
sudo ip link set dev br0 up
sudo ip link set dev ens3 up

sudo nano /etc/qemu/bridge.conf

sudo nano /etc/netplan/01-netcfg.yaml

network:
  version: 2
  ethernets:
    ens3:  
      dhcp4: no
      addresses:
        - 192.168.1.254/24
        
        sudo netplan apply

sudo nano /etc/sysctl.conf
net.ipv4.ip_forward=1
sudo sysctl -p
sudo ip route add 192.168.2.0/24 via 192.168.1.254 dev enp0s3
sudo ip route add 192.168.4.0/24 via 192.168.1.254 dev enp0s3

Edit /etc/netplan/01-netcfg.yaml to assign static IPs:

network:
  version: 2
  ethernets:
    ens3:  # Replace with your VM's interface name
      dhcp4: no
      addresses:
        - 192.168.4.254/24
      routes:
        - to: 192.168.2.0/24
          via: 192.168.2.254
        - to: 192.168.1.0/24
          via: 192.168.2.254
        - to: 192.168.3.0/24
          via: 192.168.2.254
        
Modify /etc/netplan/01-netcfg.yaml for each VM:
network:
  version: 2
  ethernets:
    ens3:
      dhcp4: no
      addresses:
        - 192.168.2.254/24

sudo netplan apply

On Desktop 1:
sudo ip route add 192.168.2.0/24 via 192.168.1.254 dev enp0s3

On Desktop :
sudo ip route add 192.168.1.0/24 via 192.168.2.254 dev enp0s3


sudo ip route add 192.168.2.0/24 via 192.168.2.254 dev ens3
sudo ip route add 192.168.3.0/24 via 192.168.3.254 dev ens3
sudo ip route add 192.168.4.0/24 via 192.168.4.254 dev ens3

sudo ip route add 192.168.1.0/24 via 192.168.2.254 dev ens3
sudo ip route add 192.168.3.0/24 via 192.168.2.254 dev ens3

sudo ip route add 192.168.2.0/24 via 192.168.1.254 dev ens3
sudo ip route add 192.168.4.0/24 via 192.168.1.254 dev ens3

sudo ip route add 192.168.1.0/24 via 192.168.2.254 dev ens3
sudo ip route add 192.168.3.0/24 via 192.168.2.254 dev ens3

ip link show ens3

ip route
traceroute 192.168.x.254


cat /proc/sys/net/ipv4/ip_forward

sudo ip addr add 192.168.x.254/24 dev <interface>  # Replace x and interface
sudo ip link set <interface> up


cat /etc/resolv.conf

sudo iptables -A FORWARD -i ens3 -o ens3 -j ACCEPT
ip link show ens3
sudo traceroute 192.168.x.x
ip link set ens3 down && ip link set ens3 up
ip route show



# On host:
sudo apt install bridge-utils -y  

sudo brctl addbr virbr0          
sudo ip addr add 192.168.20.254/24
sudo ip link set virbr0 up
sudo nano /etc/netplan/01-netcfg.yaml

network:
  version: 2
  ethernets:
    ens3:
      addresses:
        - 192.168.10.254/24
      gateway4: 192.168.10.1  # Optional: Add a dummy gateway if needed
      nameservers:
        addresses:
          - 8.8.8.8
          - 8.8.4.4

# How to create a network adapter:
ip link show
Note the interface name (e.g., enp0s3, wlp3s0, or usb0) and its current state (e.g., UP, DOWN, or UNKNOWN)
sudo apt update && sudo apt full-upgrade
cd /etc/netplan

create:

sudo gedit /etc/netplan/00-installer-config.yaml


network:
  version: 2
  renderer: networkd
  ethernets:
    <interface_name>:
      dhcp4: no  # or set to "no" for static IP
      addresses: []
      gateway4: ""
      nameservers:
        search: []
        addresses: []
        
sudo netplan apply


# Setting static IP:
add the addresses key with a list of IP addresses (e.g., 192.168.1.100/24).
If you want to set a gateway, add the gateway4 key with the IP address of your default gateway.

# Run the command: 
netplan apply

# run:
ip link show

###################################################################################################
# To make a Linux host act as a router:
Enable IP forwarding to allow the host to route packets between interfaces
sudo gedit /etc/sysctl.conf
net.ipv4.ip_forward = 1
net.ipv6.ip6_forward = 1
echo 1 > /proc/sys/net/ipv4/ip_forward
echo 1 > /proc/sys/net/ipv6/ip6_forward

# Configure the routing tables to specify how packets should be routed between interfaces 
You can do this using the:
ip route

# NAT (Network Address Translation): If you want to allow devices on one network to access the internet through the host, you’ll need to configure NAT:
You can use:
iptables:
echo 1 > /proc/sys/net/ipv4/ip_forward
iptables -t nat -A POSTROUTING -o eth0 -s 192.168.100.0/24 -j MASQUERADE

This sets up NAT on eth0 for the 192.168.100.0/24 network.

Allow forwarding between interfaces:
iptables -A FORWARD -i eth1 -o eth0 -j ACCEPT

This allows traffic from eth1 to be forwarded to eth0.

Configure routing tables:
ip route add 192.168.100.0/24 dev eth1
ip route add default gw 192.168.200.254 dev eth0

These add routes for the 192.168.100.0/24 network on eth1 and set the default gateway for the host on eth0


###
 or 
nftables

# Firewall rules: Configure firewall rules to allow incoming and outgoing traffic on the interfaces and ports you need:

########################################################################################################################
