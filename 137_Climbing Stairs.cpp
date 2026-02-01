/*
137. Climbing Stairs
Return number of ways to climb n stairs taking 1 or 2 steps (Fibonacci).
*/
#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
    if (n <= 2) return n;
    int a = 1, b = 2;
    for (int i = 3; i <= n; ++i) {
        int c = a + b;
        a = b; b = c;
    }
    return b;
}

int main() {
    cout << "climbStairs(2) = " << climbStairs(2) << "\n"; // 2
    cout << "climbStairs(3) = " << climbStairs(3) << "\n"; // 3
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
