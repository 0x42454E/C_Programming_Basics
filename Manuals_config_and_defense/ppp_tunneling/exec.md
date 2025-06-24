install pppoe
configure /etc/ppp/pppoe-server-options:
noauth 
local 
lcp-echo-interval 30
lcp-echo-failure 4

then add to /etc/ppp/pap-secrets:
"user1" * "password1"

Start a PPPoE server:
sudo pppoe-server -I <interface_name> -L <server_ip> -R <client_ip_pool_start>

on the client side:
configure /etc/ppp/peers/myconnection:
noauth
user "user1" 
remotename pppoe 
plugin rp-pppoe.so 
eth0
`
configure file:
/etc/ppp/pap-secrets:
"user1" * "password1"

start connection:
sudo pppd call myconnection

sudo tail -f /var/log/syslog