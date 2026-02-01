/*
130. Bitwise AND of Numbers Range
Compute the bitwise AND of all numbers in the range [left, right].
Shift both numbers to the right until equal, counting shifts, then shift back.
*/
#include <bits/stdc++.h>
using namespace std;

int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    while (left < right) {
        left >>= 1;
        right >>= 1;
        ++shift;
    }
    return left << shift;
}

int main() {
    cout << "rangeBitwiseAnd(5,7) = " << rangeBitwiseAnd(5,7) << "\n"; // 4
    cout << "rangeBitwiseAnd(0,1) = " << rangeBitwiseAnd(0,1) << "\n"; // 0
    cout << "rangeBitwiseAnd(1,1) = " << rangeBitwiseAnd(1,1) << "\n"; // 1
    return 0;
}

// Time Complexity: O(log M) where M is range width in bits
// Space Complexity: O(1)
