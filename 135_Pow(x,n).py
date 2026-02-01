"""
135. Pow(x,n)
Fast exponentiation for x^n, handles negative exponents.
"""

def my_pow(x: float, n: int) -> float:
    if n == 0:
        return 1.0
    exp = abs(n)
    res = 1.0
    base = x
    while exp > 0:
        if exp & 1:
            res *= base
        base *= base
        exp >>= 1
    return 1.0 / res if n < 0 else res

if __name__ == '__main__':
    print('myPow(2.0,10) =', my_pow(2.0,10))
    print('myPow(2.1,3) =', my_pow(2.1,3))
    print('myPow(2.0,-2) =', my_pow(2.0,-2))

# Time Complexity: O(log |n|)
# Space Complexity: O(1)
