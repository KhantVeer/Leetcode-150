"""
130. Bitwise AND of Numbers Range
Return the bitwise AND of all numbers in [left, right]. Shift until equal and shift back.
"""
def range_bitwise_and(left: int, right: int) -> int:
    shift = 0
    while left < right:
        left >>= 1
        right >>= 1
        shift += 1
    return left << shift

if __name__ == '__main__':
    print('rangeBitwiseAnd(5,7) =', range_bitwise_and(5,7))  # 4
    print('rangeBitwiseAnd(0,1) =', range_bitwise_and(0,1))  # 0
    print('rangeBitwiseAnd(1,1) =', range_bitwise_and(1,1))  # 1

# Time Complexity: O(log M)
# Space Complexity: O(1)
