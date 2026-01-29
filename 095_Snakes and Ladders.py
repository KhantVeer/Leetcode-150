"""
Snakes and Ladders
Find minimum moves to win using BFS on 1D-mapped board.
"""
from collections import deque
from typing import List

def snakes_and_ladders(board: List[List[int]]) -> int:
    n = len(board)
    cells = [0]*(n*n+1)
    idx = 1
    for i in range(n-1, -1, -1):
        row = board[i]
        if (n-1-i) % 2 == 0:
            for v in row:
                cells[idx] = v; idx += 1
        else:
            for v in reversed(row):
                cells[idx] = v; idx += 1
    dist = [-1]*(n*n+1)
    dist[1] = 0
    q = deque([1])
    while q:
        u = q.popleft()
        if u == n*n: return dist[u]
        for d in range(1,7):
            v = u + d
            if v > n*n: break
            if cells[v] != -1: v = cells[v]
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                q.append(v)
    return -1

if __name__ == '__main__':
    b = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
    print('Min moves:', snakes_and_ladders(b))

# Time Complexity: O(n^2)
# Space Complexity: O(n^2)
