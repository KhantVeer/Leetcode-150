"""
Word Ladder
Find shortest transformation sequence length from beginWord to endWord.
"""
from collections import deque
from typing import List

def ladder_length(beginWord: str, endWord: str, wordList: List[str]) -> int:
    dicts = set(wordList)
    if endWord not in dicts: return 0
    q = deque([(beginWord,1)])
    vis = {beginWord}
    while q:
        w,d = q.popleft()
        if w == endWord: return d
        for i in range(len(w)):
            for c in 'abcdefghijklmnopqrstuvwxyz':
                if c == w[i]: continue
                t = w[:i] + c + w[i+1:]
                if t in dicts and t not in vis:
                    vis.add(t); q.append((t,d+1))
    return 0

if __name__ == '__main__':
    print('Ladder length:', ladder_length('hit','cog',['hot','dot','dog','lot','log','cog']))

# Time Complexity: O(M * N * 26)
# Space Complexity: O(N)
