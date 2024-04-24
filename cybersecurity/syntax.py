# Cybersecurity

# passwords

# brute force attack

# crack.py

from string import  #ascii_letters #digits
from itertools import product

for passcode in product(ascii_letters, repeat=4):
    print(passcode)
