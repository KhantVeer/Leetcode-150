/*
127. Number of 1 Bits
Write a function that takes an unsigned integer and returns the number of '1' bits it has (Hamming weight).
Use the n &= (n-1) trick to clear the lowest set bit each iteration.
*/
#include <bits/stdc++.h>
using namespace std;

int hammingWeight(uint32_t n) {
    int cnt = 0;
    while (n) {
        n &= (n - 1);
        ++cnt;
    }
    return cnt;
}

int main() {
    uint32_t a = 0b00000000000000000000000000001011u;
    cout << "hammingWeight(0b1011) = " << hammingWeight(a) << "\n"; // 3
    uint32_t b = 0b00000000000000000000000010000000u;
    cout << "hammingWeight(0b10000000) = " << hammingWeight(b) << "\n"; // 1
    uint32_t c = 0u;
    cout << "hammingWeight(0) = " << hammingWeight(c) << "\n"; // 0
    return 0;
}

// Time Complexity: O(# of set bits) <= O(32) = O(1)
// Space Complexity: O(1)
