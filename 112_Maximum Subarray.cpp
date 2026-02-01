/*
112. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
We use Kadane's algorithm (linear time, constant space).
*/
#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int best = nums[0];
    int cur = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        cur = max(nums[i], cur + nums[i]);
        best = max(best, cur);
    }
    return best;
}

int main() {
    vector<int> a{ -2,1,-3,4,-1,2,1,-5,4 };
    cout << "MaxSubArray([-2,1,-3,4,-1,2,1,-5,4]) = " << maxSubArray(a) << "\n"; // expect 6

    vector<int> b{1};
    cout << "MaxSubArray([1]) = " << maxSubArray(b) << "\n"; // expect 1

    vector<int> c{-1,-2,-3};
    cout << "MaxSubArray([-1,-2,-3]) = " << maxSubArray(c) << "\n"; // expect -1
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
