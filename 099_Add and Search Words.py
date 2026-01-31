"""
Design Add and Search Words Data Structure
Support addWord and search with '.' wildcard using Trie + DFS.
"""
from typing import Dict

class TrieNode:
    def __init__(self):
        self.children: Dict[str, 'TrieNode'] = {}
        self.end = False

class WordDictionary:
    def __init__(self):
        self.root = TrieNode()
    def addWord(self, word: str) -> None:
        p = self.root
        for c in word:
            if c not in p.children: p.children[c] = TrieNode()
            p = p.children[c]
        p.end = True
    def search(self, word: str) -> bool:
        def dfs(node: TrieNode, i: int) -> bool:
            if not node: return False
            if i == len(word): return node.end
            c = word[i]
            if c == '.':
                for child in node.children.values():
                    if dfs(child, i+1): return True
                return False
            else:
                return c in node.children and dfs(node.children[c], i+1)
        return dfs(self.root, 0)

if __name__ == '__main__':
    wd = WordDictionary(); wd.addWord('bad'); wd.addWord('dad'); wd.addWord('mad')
    print(wd.search('pad'), wd.search('bad'), wd.search('.ad'), wd.search('b..'))

# Time Complexity: add O(L), search depends on wildcards
# Space Complexity: O(total chars)
