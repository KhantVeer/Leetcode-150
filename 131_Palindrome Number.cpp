/*
131. Palindrome Number
Check whether an integer reads the same forwards and backwards.
Avoid converting to string by reversing half of the number.
*/
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    int rev = 0;
    while (x > rev) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return x == rev || x == rev/10;
}

int main() {
    cout << "isPalindrome(121) = " << (isPalindrome(121) ? "true" : "false") << "\n"; // true
    cout << "isPalindrome(-121) = " << (isPalindrome(-121) ? "true" : "false") << "\n"; // false
    cout << "isPalindrome(10) = " << (isPalindrome(10) ? "true" : "false") << "\n"; // false
    return 0;
}

// Time Complexity: O(log10(x))
// Space Complexity: O(1)
