/*
145. Longest Palindromic Substring
Find the longest palindromic substring by expanding around centers (O(n^2)).
*/
#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    int n = s.size();
    if (n < 2) return s;
    int start = 0, maxLen = 1;
    for (int i = 0; i < n; ++i) {
        // odd
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) { start = l; maxLen = r - l + 1; }
            --l; ++r;
        }
        // even
        l = i; r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) { start = l; maxLen = r - l + 1; }
            --l; ++r;
        }
    }
    return s.substr(start, maxLen);
}

int main() {
    cout << longestPalindrome("babad") << "\n"; // "bab" or "aba"
    cout << longestPalindrome("cbbd") << "\n"; // "bb"
    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)
