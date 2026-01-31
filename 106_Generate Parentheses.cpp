// Generate Parentheses
// Generate all combinations of well-formed parentheses for n pairs.
// Solution: backtracking tracking counts of open and close parens.
#include <bits/stdc++.h>
using namespace std;

vector<string> generateParenthesis(int n) {
    vector<string> res;
    function<void(string,int,int)> dfs = [&](string cur, int open, int close){
        if(cur.size() == 2*n){ res.push_back(cur); return; }
        if(open < n) dfs(cur + '(', open+1, close);
        if(close < open) dfs(cur + ')', open, close+1);
    };
    dfs("", 0, 0);
    return res;
}

int main(){
    auto r = generateParenthesis(3);
    cout<<"Generate Parentheses (n=3):\n";
    for(auto &s: r) cout<<s<<"\n";
    return 0;
}

// Time Complexity: Catalan number ~ O(4^n / (n*sqrt(n))) outputs
// Space Complexity: O(n) recursion + output
