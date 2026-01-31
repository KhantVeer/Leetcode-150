"""
Generate Parentheses
Return all combinations of well-formed parentheses for n pairs.
"""
from typing import List

def generate_parentheses(n: int) -> List[str]:
    res = []
    def dfs(cur, open_count, close_count):
        if len(cur) == 2*n:
            res.append(''.join(cur)); return
        if open_count < n:
            cur.append('('); dfs(cur, open_count+1, close_count); cur.pop()
        if close_count < open_count:
            cur.append(')'); dfs(cur, open_count, close_count+1); cur.pop()
    dfs([], 0, 0)
    return res

if __name__ == '__main__':
    print('Generate Parentheses n=3:', generate_parentheses(3))

# Time Complexity: Catalan number output size
# Space Complexity: O(n)
