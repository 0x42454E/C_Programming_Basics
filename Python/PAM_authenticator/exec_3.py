#
# PAM-Based User Authentication Script
# ------------------------------------
# Author: Ben  
#
# Description:
# ------------
# This script uses the `python-pam` module to authenticate system users via 
# Pluggable Authentication Modules (PAM).
#
# Functionality:
# --------------
# - Prompts the user to enter their system username and password.
# - Uses `pam.pam().authenticate()` to verify credentials.
# - Prints whether the authentication was successful or failed.
#
# Requirements:
# -------------
# - Install the PAM Python bindings:
#     pip install python-pam
# - Must be run on a system that supports PAM (e.g., Linux).
#
# Security Notes:
# ---------------
# - Password input is hidden using `getpass.getpass()` for secure entry.
# - Does not store or log credentials.
# - Should be executed in a secure terminal/session to avoid leaking credentials.
#
# Example:
# --------
# $ python3 auth_script.py
# Enter username: ben
# Enter password:
# Authentication successful for ben
#


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