/*
126. Reverse Bits
Reverse the bits of a given 32-bit unsigned integer.
*/
#include <bits/stdc++.h>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t rev = 0;
    for (int i = 0; i < 32; ++i) {
        rev <<= 1;
        rev |= (n & 1);
        n >>= 1;
    }
    return rev;
}

int main() {
    uint32_t x = 0b00000010100101000001111010011100u;
    cout << "reverseBits(...) = " << reverseBits(x) << "\n"; // prints integer value
    // example with all ones
    uint32_t y = 0b11111111111111111111111111111101u;
    cout << "reverseBits(...) = " << reverseBits(y) << "\n";
    return 0;
}

// Time Complexity: O(32) = O(1)
// Space Complexity: O(1)
