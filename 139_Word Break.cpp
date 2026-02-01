/*
139. Word Break
Given a string s and a dictionary of words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
Use DP where dp[i] is true if s[:i] can be segmented.
*/
#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<bool> dp(n+1,false);
    dp[0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && dict.count(s.substr(j, i-j))) { dp[i] = true; break; }
        }
    }
    return dp[n];
}

int main() {
    string s = "leetcode";
    vector<string> dict{"leet","code"};
    cout << "wordBreak('leetcode') = " << (wordBreak(s, dict) ? "true" : "false") << "\n"; // true
    string t = "applepenapple";
    vector<string> dict2{"apple","pen"};
    cout << "wordBreak('applepenapple') = " << (wordBreak(t, dict2) ? "true" : "false") << "\n"; // true
    return 0;
}

// Time Complexity: O(n^2 * k) substring cost, can be improved
// Space Complexity: O(n)
