/*
135. Pow(x, n)
Compute x raised to the power n using fast exponentiation (binary exponentiation).
*/
#include <bits/stdc++.h>
using namespace std;

double myPow(double x, long long n) {
    if (n == 0) return 1.0;
    long long exp = llabs(n);
    double res = 1.0;
    double base = x;
    while (exp > 0) {
        if (exp & 1) res *= base;
        base *= base;
        exp >>= 1;
    }
    return n < 0 ? 1.0 / res : res;
}

int main() {
    cout << "myPow(2.0,10) = " << myPow(2.0,10) << "\n"; // 1024
    cout << "myPow(2.1,3) = " << myPow(2.1,3) << "\n"; // ~9.261
    cout << "myPow(2.0,-2) = " << myPow(2.0,-2) << "\n"; // 0.25
    return 0;
}

// Time Complexity: O(log |n|)
// Space Complexity: O(1)
