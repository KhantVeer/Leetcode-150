"""
133. Factorial Trailing Zeroes
Count number of trailing zeros in n! by summing floor(n/5^i).
"""

def trailing_zeroes(n: int) -> int:
    count = 0
    while n > 0:
        n //= 5
        count += n
    return count

if __name__ == '__main__':
    print('trailingZeroes(3) =', trailing_zeroes(3))
    print('trailingZeroes(5) =', trailing_zeroes(5))
    print('trailingZeroes(100) =', trailing_zeroes(100))

# Time Complexity: O(log_5 n)
# Space Complexity: O(1)
