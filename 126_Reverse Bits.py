"""
126. Reverse Bits
Reverse bits of a 32-bit unsigned integer. Return as integer.
"""
def reverse_bits(n: int) -> int:
    rev = 0
    for _ in range(32):
        rev = (rev << 1) | (n & 1)
        n >>= 1
    return rev

if __name__ == '__main__':
    x = 0b00000010100101000001111010011100
    print('reverseBits(...) =', reverse_bits(x))
    y = 0b11111111111111111111111111111101
    print('reverseBits(...) =', reverse_bits(y))

# Time Complexity: O(1) (32 iterations)
# Space Complexity: O(1)
