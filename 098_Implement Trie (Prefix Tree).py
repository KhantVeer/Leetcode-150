"""
Implement Trie (Prefix Tree)
Insert, search and startsWith methods.
"""
from typing import Dict

class TrieNode:
    def __init__(self):
        self.children: Dict[str, 'TrieNode'] = {}
        self.end = False

class Trie:
    def __init__(self):
        self.root = TrieNode()
    def insert(self, word: str) -> None:
        p = self.root
        for c in word:
            if c not in p.children: p.children[c] = TrieNode()
            p = p.children[c]
        p.end = True
    def search(self, word: str) -> bool:
        p = self.root
        for c in word:
            if c not in p.children: return False
            p = p.children[c]
        return p.end
    def startsWith(self, prefix: str) -> bool:
        p = self.root
        for c in prefix:
            if c not in p.children: return False
            p = p.children[c]
        return True

if __name__ == '__main__':
    t = Trie(); t.insert('apple'); print(t.search('apple'), t.search('app'), t.startsWith('app'))
    t.insert('app'); print(t.search('app'))

# Time Complexity: O(L)
# Space Complexity: O(total chars)
