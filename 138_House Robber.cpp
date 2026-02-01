/*
138. House Robber
Max amount we can rob without robbing adjacent houses (classic DP).
*/
#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    int prev2 = nums[0], prev1 = max(nums[0], nums[1]);
    for (int i = 2; i < n; ++i) {
        int cur = max(prev1, prev2 + nums[i]);
        prev2 = prev1; prev1 = cur;
    }
    return prev1;
}

int main() {
    vector<int> a{1,2,3,1};
    cout << "rob([1,2,3,1]) = " << rob(a) << "\n"; // 4
    vector<int> b{2,7,9,3,1};
    cout << "rob([2,7,9,3,1]) = " << rob(b) << "\n"; // 12
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
