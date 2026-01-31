"""
Permutations
Return all permutations of a list of distinct integers.
"""
from typing import List

def permute(nums: List[int]) -> List[List[int]]:
    res = []
    def dfs(i):
        if i == len(nums): res.append(nums.copy()); return
        for j in range(i, len(nums)):
            nums[i], nums[j] = nums[j], nums[i]
            dfs(i+1)
            nums[i], nums[j] = nums[j], nums[i]
    dfs(0)
    return res

if __name__ == '__main__':
    print('Permutations:', permute([1,2,3]))

# Time Complexity: O(n * n!)
# Space Complexity: O(n)
