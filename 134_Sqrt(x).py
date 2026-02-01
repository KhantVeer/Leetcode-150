"""
134. Sqrt(x)
Return integer part of square root using binary search.
"""

def my_sqrt(x: int) -> int:
    if x < 2:
        return x
    l, r, ans = 1, x//2, 1
    while l <= r:
        m = (l + r) // 2
        sq = m * m
        if sq == x:
            return m
        if sq < x:
            ans = m
            l = m + 1
        else:
            r = m - 1
    return ans

if __name__ == '__main__':
    print('mySqrt(4) =', my_sqrt(4))
    print('mySqrt(8) =', my_sqrt(8))
    print('mySqrt(1) =', my_sqrt(1))

# Time Complexity: O(log x)
# Space Complexity: O(1)
