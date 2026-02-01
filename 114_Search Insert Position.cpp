/*
114. Search Insert Position
Given a sorted array and a target value, return the index if the target is found.
If not, return the index where it would be inserted in order.
Use binary search to achieve O(log n).
*/
#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = (int)nums.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (nums[m] == target) return m;
        if (nums[m] < target) l = m + 1;
        else r = m - 1;
    }
    return l;
}

int main() {
    vector<int> a{1,3,5,6};
    cout << "searchInsert([1,3,5,6],5) = " << searchInsert(a,5) << "\n"; // 2
    cout << "searchInsert([1,3,5,6],2) = " << searchInsert(a,2) << "\n"; // 1
    cout << "searchInsert([1,3,5,6],7) = " << searchInsert(a,7) << "\n"; // 4
    return 0;
}

// Time Complexity: O(log n)
// Space Complexity: O(1)
