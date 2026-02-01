/*
118. Find First and Last Position of Element in Sorted Array
Return the starting and ending position of a given target value. Use binary searches for left and right bounds.
*/
#include <bits/stdc++.h>
using namespace std;

int left_bound(const vector<int>& nums, int target) {
    int l = 0, r = (int)nums.size() - 1, ans = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (nums[m] >= target) {
            if (nums[m] == target) ans = m;
            r = m - 1;
        } else l = m + 1;
    }
    return ans;
}

int right_bound(const vector<int>& nums, int target) {
    int l = 0, r = (int)nums.size() - 1, ans = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (nums[m] <= target) {
            if (nums[m] == target) ans = m;
            l = m + 1;
        } else r = m - 1;
    }
    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
    return {left_bound(nums, target), right_bound(nums, target)};
}

int main() {
    vector<int> a{5,7,7,8,8,10};
    auto r = searchRange(a,8);
    cout << "searchRange([5,7,7,8,8,10],8) = [" << r[0] << "," << r[1] << "]\n"; // [3,4]
    auto r2 = searchRange(a,6);
    cout << "searchRange(...,6) = [" << r2[0] << "," << r2[1] << "]\n"; // [-1,-1]
    vector<int> b{};
    auto r3 = searchRange(b,0);
    cout << "searchRange([],0) = [" << r3[0] << "," << r3[1] << "]\n"; // [-1,-1]
    return 0;
}

// Time Complexity: O(log n)
// Space Complexity: O(1)
