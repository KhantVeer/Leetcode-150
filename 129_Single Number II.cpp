/*
129. Single Number II
Given an array of integers, every element appears three times except for one which appears once. Find that single one.
Use bitwise counting: sum bits modulo 3.
*/
#include <bits/stdc++.h>
using namespace std;

int singleNumberII(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < 32; ++i) {
        int sum = 0;
        for (int n : nums) sum += ( (n >> i) & 1 );
        if (sum % 3) result |= (1 << i);
    }
    return result;
}

int main() {
    vector<int> a{2,2,3,2};
    cout << "singleNumberII([2,2,3,2]) = " << singleNumberII(a) << "\n"; // 3
    vector<int> b{0,1,0,1,0,1,99};
    cout << "singleNumberII(...,99) = " << singleNumberII(b) << "\n"; // 99
    return 0;
}

// Time Complexity: O(32*n) = O(n)
// Space Complexity: O(1)
