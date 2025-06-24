"""
Brute-force SHA-256 hash cracker.
Attempts to recover plaintext passwords by matching SHA-256 hashes.
Uses lowercase letters and digits for candidate generation.
Prints the time taken to crack each password.
"""

import hashlib
import itertools
import string
from datetime import datetime
from itertools import product
from time import time

pass1 = hashlib.sha256(b"aopb").hexdigest()
pass2 = hashlib.sha256(b"jmzxq").hexdigest()
pass3 = hashlib.sha256(b"186953").hexdigest()
pass4 = hashlib.sha256(b"1144823").hexdigest()
pass5 = hashlib.sha256(b"89461324").hexdigest()
pass6 = hashlib.sha256(b"oyinsq").hexdigest()
pass7 = hashlib.sha256(b"nj67z").hexdigest()

def brute(val, length):
    cur_time = datetime.now()
    chars = string.digits + string.ascii_lowercase
    for guess in itertools.product(chars, repeat=length):
        password = ''.join(guess)
        if val == hashlib.sha256(password.encode()).hexdigest():
            print(datetime.now() - cur_time)
            return password


print(brute(pass7, 5))