/*
132. Plus One
Given a non-empty array of digits representing a non-negative integer, add one to the integer.
Handle carries across digits; if all 9s, return new array with leading 1.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    for (int i = n-1; i >= 0; --i) {
        if (digits[i] < 9) { digits[i]++; return digits; }
        digits[i] = 0;
    }
    digits.insert(digits.begin(), 1);
    return digits;
}

int main() {
    vector<int> a{1,2,3};
    auto r = plusOne(a);
    cout << "plusOne([1,2,3]) = "; for (int d: r) cout << d; cout << "\n"; // 124
    vector<int> b{9,9,9};
    auto r2 = plusOne(b);
    cout << "plusOne([9,9,9]) = "; for (int d: r2) cout << d; cout << "\n"; // 1000
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1) or O(n) if resized
