"""
137. Climbing Stairs
Dynamic programming / Fibonacci sequence for step counts.
"""
def climb_stairs(n: int) -> int:
    if n <= 2: return n
    a, b = 1, 2
    for _ in range(3, n+1):
        a, b = b, a + b
    return b

if __name__ == '__main__':
    print('climbStairs(2) =', climb_stairs(2))
    print('climbStairs(3) =', climb_stairs(3))

# Time Complexity: O(n)
# Space Complexity: O(1)
