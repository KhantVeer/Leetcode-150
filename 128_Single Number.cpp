/*
128. Single Number
Given a non-empty array of integers where every element appears twice except for one, find that single one.
XOR of all numbers yields the unique element.
*/
#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int x = 0;
    for (int v : nums) x ^= v;
    return x;
}

int main() {
    vector<int> a{2,2,1};
    cout << "singleNumber([2,2,1]) = " << singleNumber(a) << "\n"; // 1
    vector<int> b{4,1,2,1,2};
    cout << "singleNumber([4,1,2,1,2]) = " << singleNumber(b) << "\n"; // 4
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
