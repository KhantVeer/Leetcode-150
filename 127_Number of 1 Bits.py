"""
127. Number of 1 Bits
Count the number of '1' bits in a 32-bit integer (Hamming weight).
"""
def hamming_weight(n: int) -> int:
    # Treat n as unsigned 32-bit
    n &= 0xFFFFFFFF
    cnt = 0
    while n:
        n &= n - 1
        cnt += 1
    return cnt

if __name__ == '__main__':
    print('hammingWeight(0b1011) =', hamming_weight(0b00000000000000000000000000001011))  # 3
    print('hammingWeight(0b10000000) =', hamming_weight(0b00000000000000000000000010000000))  # 1
    print('hammingWeight(0) =', hamming_weight(0))  # 0

# Time Complexity: O(# of set bits) <= O(32)
# Space Complexity: O(1)
