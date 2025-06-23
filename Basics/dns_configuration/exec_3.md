https://www.digitalocean.com/community/tutorials/how-to-configure-bind-as-a-private-network-dns-server-on-ubuntu-20-04

#install a dns server:
sudo apt install bind9 bind9utils bind9-doc

sudo nano /etc/default/named

. . .
OPTIONS="-u bind -4"

sudo systemctl restart bind9

#Config:
sudo nano /etc/bind/named.conf.options

acl "trusted" {
        10.128.10.11;    # ns1 
        10.128.20.12;    # ns2
        10.128.100.101;  # host1
        10.128.200.102;  # host2
};

options {

#specify your DNS zones:
sudo gedit /etc/bind/named.conf.local

#define DNS records for forward DNS lookups:
sudo mkdir /etc/bind/zones
sudo cp /etc/bind/db.local /etc/bind/zones/db.example.com
sudo nano /etc/bind/zones/db.example.com

#to check the syntax of the named.conf* files:
sudo named-checkconf

#The named-checkzone command can be used to check the correctness of your zone files
sudo named-checkzone nyc3.example.com /etc/bind/zones/db.nyc3.example.com

#And to check the 10.10.in-addr.arpa reverse zone configuration:
sudo named-checkzone 128.10.in-addr.arpa /etc/bind/zones/db.10.128

#When all of your configuration and zone files have no errors in them, you will be ready to restart the BIND service.
sudo systemctl restart bind9s


#To allow and perform zone transfer:
sudo nano /etc/bind/named.conf.local
configure allow-transfer { any; }

#Configure the Secondary DNS Server (Slave):
s








