"""
Word Search II
Find all words from dictionary on a 2D board using Trie + DFS backtracking.
"""
from typing import List

class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = None

def build_trie(words: List[str]) -> TrieNode:
    root = TrieNode()
    for w in words:
        node = root
        for c in w:
            node = node.children.setdefault(c, TrieNode())
        node.word = w
    return root

def find_words(board: List[List[str]], words: List[str]) -> List[str]:
    root = build_trie(words)
    m, n = len(board), len(board[0]) if board else 0
    res = []
    def dfs(i,j,node):
        c = board[i][j]
        if c not in node.children: return
        nxt = node.children[c]
        if nxt.word:
            res.append(nxt.word); nxt.word = None
        board[i][j] = '#'
        for di,dj in ((1,0),(-1,0),(0,1),(0,-1)):
            ni, nj = i+di, j+dj
            if 0<=ni<m and 0<=nj<n and board[ni][nj] != '#': dfs(ni,nj,nxt)
        board[i][j] = c
    for i in range(m):
        for j in range(n):
            dfs(i,j,root)
    return res

if __name__ == '__main__':
    board = [['o','a','a','n'],['e','t','a','e'],['i','h','k','r'],['i','f','l','v']]
    words = ["oath","pea","eat","rain"]
    print('Found:', find_words(board, words))

# Time Complexity: O(M*N*4^L) worst-case, pruned by trie
# Space Complexity: O(sum lengths of words)
