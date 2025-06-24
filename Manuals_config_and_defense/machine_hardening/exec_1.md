hardening process:
1) check and manage open ports. netstat -tulnp
2) close all irelevant and change all default
3) check open files. lsof -i -P -n
4) close unnecessary
5) find all installed software and delete all unused and unnecessary 
6) dpkg --list / apt list --installed
7) check processes and close unnecessary | ps aux | top
8) implement least privilege by checking all users groups, audit permissions guided by zero-trust policy.
9) cut -d: -f1 /etc/passwd and
10) cut -d: -f1 /etc/group
11) enforce password and MFA policies for new users
12) install essential security features: firewall, edr/AV, ids, ips.
13) establish proxy server to delegate all your connections and use VPN to connect to the internet from it.
14) ensure automatic updates
15) implement proper segmentation if the need arises
16) encrypt swap space and databases 
17) audit certificates allowed
18) /etc/ssl/certs/
19) install and manage logging systems
20) install tools that block brute force attempts 
21) enable and ensure secure boot and disable booting from external devices 
22) restrict execution location
23) edit /etc/fstab
24) disable unnecessary kernel modules | lsmod
25) establish a sandbox environment for potentially malicious application using docker
26) establish backup disaster recovery policy 
27) secure physical access
28) educate users and minimize social engineering attack
29) ensure memory safety techniques enabled
30) whitelist applications for example | apparmor