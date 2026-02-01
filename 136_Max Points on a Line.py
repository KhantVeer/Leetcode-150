"""
136. Max Points on a Line
Count maximum points collinear using slope normalization (gcd).
"""
from typing import List, Tuple
from collections import defaultdict
import math

def max_points(points: List[Tuple[int,int]]) -> int:
    n = len(points)
    if n < 3: return n
    ans = 0
    for i in range(n):
        cnt = defaultdict(int)
        duplicates = 0
        local_max = 0
        xi, yi = points[i]
        for j in range(i+1, n):
            xj, yj = points[j]
            dx = xj - xi; dy = yj - yi
            if dx == 0 and dy == 0:
                duplicates += 1
                continue
            g = math.gcd(dx, dy)
            if g != 0:
                dx //= g; dy //= g
            if dx < 0:
                dx = -dx; dy = -dy
            elif dx == 0 and dy < 0:
                dy = -dy
            key = (dx, dy)
            cnt[key] += 1
            local_max = max(local_max, cnt[key])
        ans = max(ans, local_max + duplicates + 1)
    return ans

if __name__ == '__main__':
    print('maxPoints([(1,1),(2,2),(3,3)]) =', max_points([(1,1),(2,2),(3,3)]))
    print('maxPoints([...]) =', max_points([(1,1),(3,2),(5,3),(4,1),(2,3),(1,4)]))

# Time Complexity: O(n^2)
# Space Complexity: O(n)
