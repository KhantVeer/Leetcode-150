/*
115. Search a 2D Matrix
Write an efficient algorithm that searches for a value in an m x n matrix. The matrix has the properties:
 - Integers in each row are sorted from left to right.
 - The first integer of each row is greater than the last integer of the previous row.
Treat the matrix as a flattened sorted array and perform binary search.
*/
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    int m = matrix.size(), n = matrix[0].size();
    int l = 0, r = m * n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int val = matrix[mid / n][mid % n];
        if (val == target) return true;
        if (val < target) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}

int main() {
    vector<vector<int>> mat{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout << "searchMatrix(..., 3) = " << (searchMatrix(mat, 3) ? "true" : "false") << "\n"; // true
    cout << "searchMatrix(..., 13) = " << (searchMatrix(mat, 13) ? "true" : "false") << "\n"; // false
    vector<vector<int>> empty;
    cout << "searchMatrix(empty, 1) = " << (searchMatrix(empty,1) ? "true" : "false") << "\n"; // false
    return 0;
}

// Time Complexity: O(log(m*n)) = O(log m + log n)
// Space Complexity: O(1)
