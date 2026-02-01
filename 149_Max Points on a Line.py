"""
149. Max Points on a Line
Count maximum points on a straight line using normalized slopes via gcd and a hashmap.
"""
from typing import List, Tuple
from collections import defaultdict
import math

def max_points(points: List[Tuple[int,int]]) -> int:
    n = len(points)
    if n < 3: return n
    best = 0
    for i in range(n):
        cnt = defaultdict(int)
        duplicates = 0
        local_max = 0
        x1,y1 = points[i]
        for j in range(i+1,n):
            x2,y2 = points[j]
            dx = x2 - x1; dy = y2 - y1
            if dx==0 and dy==0:
                duplicates += 1; continue
            g = math.gcd(dx, dy)
            dx //= g; dy //= g
            if dx < 0:
                dx, dy = -dx, -dy
            if dx == 0: dy = 1
            if dy == 0: dx = 1
            cnt[(dx, dy)] += 1
            local_max = max(local_max, cnt[(dx, dy)])
        best = max(best, local_max + duplicates + 1)
    return best

if __name__ == '__main__':
    pts1 = [(1,1),(2,2),(3,3)]
    print('maxPoints(pts1) =', max_points(pts1))
    pts2 = [(1,1),(3,2),(5,3),(4,1),(2,3),(1,4)]
    print('maxPoints(pts2) =', max_points(pts2))

# Time Complexity: O(n^2)
# Space Complexity: O(n)
