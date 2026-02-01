"""
113. Maximum Sum Circular Subarray
Compute maximum subarray sum for a circular array using Kadane's algorithm and the inverted-min trick.
"""
from typing import List

def kadane_max(nums: List[int]) -> int:
    cur = best = nums[0]
    for x in nums[1:]:
        cur = max(x, cur + x)
        best = max(best, cur)
    return best

def max_subarray_circular(nums: List[int]) -> int:
    max_k = kadane_max(nums)
    total = sum(nums)
    # min subarray (Kadane on inverted criteria)
    cur_min = min_k = nums[0]
    for x in nums[1:]:
        cur_min = min(x, cur_min + x)
        min_k = min(min_k, cur_min)
    if min_k == total:
        return max_k
    return max(max_k, total - min_k)

if __name__ == '__main__':
    print('MaxCircular([1,-2,3,-2]) =', max_subarray_circular([1,-2,3,-2]))  # 3
    print('MaxCircular([5,-3,5]) =', max_subarray_circular([5,-3,5]))  # 10
    print('MaxCircular([-3,-2,-3]) =', max_subarray_circular([-3,-2,-3]))  # -2

# Time Complexity: O(n)
# Space Complexity: O(1)
