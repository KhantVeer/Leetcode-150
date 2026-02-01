"""
115. Search a 2D Matrix
Treat the matrix as a flattened sorted array and perform binary search.
"""
from typing import List

def search_matrix(matrix: List[List[int]], target: int) -> bool:
    if not matrix or not matrix[0]:
        return False
    m, n = len(matrix), len(matrix[0])
    l, r = 0, m * n - 1
    while l <= r:
        mid = (l + r) // 2
        val = matrix[mid // n][mid % n]
        if val == target:
            return True
        if val < target:
            l = mid + 1
        else:
            r = mid - 1
    return False

if __name__ == '__main__':
    mat = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
    print('searchMatrix(..., 3) =', search_matrix(mat, 3))
    print('searchMatrix(..., 13) =', search_matrix(mat, 13))
    print('searchMatrix(empty,1) =', search_matrix([], 1))

# Time Complexity: O(log(m*n))
# Space Complexity: O(1)
