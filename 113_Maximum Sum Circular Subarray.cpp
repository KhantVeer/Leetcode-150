/*
113. Maximum Sum Circular Subarray
Find the maximum subarray sum for a circular array. Use Kadane's algorithm for max subarray and min subarray.
If all numbers are negative, return the maximum (standard Kadane result).
*/
#include <bits/stdc++.h>
using namespace std;

int kadaneMax(const vector<int>& nums) {
    int cur = nums[0], best = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        cur = max(nums[i], cur + nums[i]);
        best = max(best, cur);
    }
    return best;
}

int maxSubarrayCircular(vector<int>& nums) {
    int max_k = kadaneMax(nums);
    int total = 0;
    int cur_min = nums[0], min_k = nums[0];
    for (int x : nums) {
        total += x;
    }
    // find min subarray
    cur_min = nums[0]; min_k = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        cur_min = min(nums[i], cur_min + nums[i]);
        min_k = min(min_k, cur_min);
    }
    if (min_k == total) return max_k; // all negative case
    return max(max_k, total - min_k);
}

int main() {
    vector<int> a{1,-2,3,-2};
    cout << "MaxCircular([1,-2,3,-2]) = " << maxSubarrayCircular(a) << "\n"; // expect 3

    vector<int> b{5,-3,5};
    cout << "MaxCircular([5,-3,5]) = " << maxSubarrayCircular(b) << "\n"; // expect 10

    vector<int> c{-3,-2,-3};
    cout << "MaxCircular([-3,-2,-3]) = " << maxSubarrayCircular(c) << "\n"; // expect -2
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
