/*
133. Factorial Trailing Zeroes
Count trailing zeros in n! by counting factors of 5.
*/
#include <bits/stdc++.h>
using namespace std;

int trailingZeroes(int n) {
    int count = 0;
    while (n > 0) {
        n /= 5;
        count += n;
    }
    return count;
}

int main() {
    cout << "trailingZeroes(3) = " << trailingZeroes(3) << "\n"; // 0
    cout << "trailingZeroes(5) = " << trailingZeroes(5) << "\n"; // 1
    cout << "trailingZeroes(100) = " << trailingZeroes(100) << "\n"; // 24
    return 0;
}

// Time Complexity: O(log_5 n)
// Space Complexity: O(1)
