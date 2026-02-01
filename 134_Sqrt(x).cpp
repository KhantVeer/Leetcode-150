/*
134. Sqrt(x)
Compute and return the integer part of the square root of x using binary search.
*/
#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    if (x < 2) return x;
    int l = 1, r = x/2, ans = 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        long long sq = 1LL * m * m;
        if (sq == x) return m;
        if (sq < x) { ans = m; l = m + 1; }
        else r = m - 1;
    }
    return ans;
}

int main() {
    cout << "mySqrt(4) = " << mySqrt(4) << "\n"; // 2
    cout << "mySqrt(8) = " << mySqrt(8) << "\n"; // 2
    cout << "mySqrt(1) = " << mySqrt(1) << "\n"; // 1
    return 0;
}

// Time Complexity: O(log x)
// Space Complexity: O(1)
