"""
125. Add Binary
Add two binary strings and return their sum as binary string.
"""
from typing import Tuple

def add_binary(a: str, b: str) -> str:
    i, j, carry = len(a)-1, len(b)-1, 0
    res = []
    while i >= 0 or j >= 0 or carry:
        s = carry
        if i >= 0:
            s += ord(a[i]) - ord('0'); i -= 1
        if j >= 0:
            s += ord(b[j]) - ord('0'); j -= 1
        res.append(chr(ord('0') + (s & 1)))
        carry = s >> 1
    return ''.join(reversed(res))

if __name__ == '__main__':
    print("addBinary('11','1') =", add_binary('11','1'))  # 100
    print("addBinary('1010','1011') =", add_binary('1010','1011'))  # 10101

# Time Complexity: O(max(len(a),len(b)))
# Space Complexity: O(max(len(a),len(b)))
