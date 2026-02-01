/*
141. Longest Increasing Subsequence
Find length of longest strictly increasing subsequence. Use patience sorting (tails + binary search) for O(n log n).
*/
#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> tails;
    for (int x : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return (int)tails.size();
}

int main() {
    vector<int> a{10,9,2,5,3,7,101,18};
    cout << "LIS length = " << lengthOfLIS(a) << "\n"; // 4
    vector<int> b{0,1,0,3,2,3};
    cout << "LIS length = " << lengthOfLIS(b) << "\n"; // 4
    return 0;
}

// Time Complexity: O(n log n)
// Space Complexity: O(n)
