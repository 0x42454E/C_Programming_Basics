import pam
import getpass



def authenticate_user(uname, passwd):
    p = pam.pam()
    if p.authenticate(uname, passwd):
        print(f"Authentication successful for {uname}")
    else:
        print(f"Authentication failed for {uname}")

username = input("Enter username: ")
password = getpass.getpass("Enter password: ")

authenticate_user(username, password)