# Cybersecurity

# passwords

# brute force attack

# crack.py

from string import ascii_letters, digits, punctuation
from itertools import product

for passcode in product(ascii_letters + digits + punctuation, repeat=8):
    print(passcode)


# hash passwords
# 1 way

# cryptography
# 2 way

