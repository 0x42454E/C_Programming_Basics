import socket

def port_scan(host):
    """Scan and print all open ports"""
    for port in range(1, 1025):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        result = s.connect_ex((host, port))
        if result == 0:
            print(f"Port {port}: OPEN")
        s.close()


port_scan("10.10.1.84")