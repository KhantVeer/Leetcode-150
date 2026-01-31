"""
Word Search
Check if a word exists in a 2D board of characters (DFS backtracking).
"""
from typing import List

def exist(board: List[List[str]], word: str) -> bool:
    m = len(board)
    if m == 0: return False
    n = len(board[0])
    def dfs(i,j,idx):
        if idx == len(word): return True
        if i<0 or j<0 or i>=m or j>=n or board[i][j] != word[idx]: return False
        tmp = board[i][j]; board[i][j] = '#'
        found = dfs(i+1,j,idx+1) or dfs(i-1,j,idx+1) or dfs(i,j+1,idx+1) or dfs(i,j-1,idx+1)
        board[i][j] = tmp
        return found
    for i in range(m):
        for j in range(len(board[0])):
            if dfs(i,j,0): return True
    return False

if __name__ == '__main__':
    board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]
    print('ABCCED exists:', exist(board, 'ABCCED'))
    print('SEE exists:', exist(board, 'SEE'))
    print('ABCB exists:', exist(board, 'ABCB'))

# Time Complexity: O(m*n*4^L)
# Space Complexity: O(L)
