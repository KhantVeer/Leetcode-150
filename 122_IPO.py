"""
122. IPO (mapped)
Maximize capital by selecting at most k projects given initial capital W, profits and capital requirements.
Use a max-heap to select best available profits.
"""
from typing import List
import heapq

def find_maximized_capital(k: int, W: int, Profits: List[int], Capital: List[int]) -> int:
    projects = sorted(zip(Capital, Profits))
    n = len(projects)
    pq = []  # max-heap via negatives
    idx = 0
    capital = W
    for _ in range(k):
        while idx < n and projects[idx][0] <= capital:
            heapq.heappush(pq, -projects[idx][1])
            idx += 1
        if not pq:
            break
        capital += -heapq.heappop(pq)
    return capital

if __name__ == '__main__':
    print('findMaximizedCapital(k=2,W=0) =', find_maximized_capital(2,0,[1,2,3],[0,1,1]))  # 4
    print('findMaximizedCapital(k=3,W=0) =', find_maximized_capital(3,0,[1,2,3],[0,1,2]))  # 6

# Time Complexity: O(n log n + k log n)
# Space Complexity: O(n)
