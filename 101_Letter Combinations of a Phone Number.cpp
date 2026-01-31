// Letter Combinations of a Phone Number
// Return all letter combinations that the number could represent (digits 2-9).
// Solution: backtracking using mapping.
#include <bits/stdc++.h>
using namespace std;

vector<string> letterCombinations(string digits){
    if(digits.empty()) return {};
    vector<string> map = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> res;
    function<void(int,string&)> dfs = [&](int i, string &cur){
        if(i==digits.size()){ res.push_back(cur); return; }
        string &letters = map[digits[i]-'0'];
        for(char c: letters){ cur.push_back(c); dfs(i+1, cur); cur.pop_back(); }
    };
    string cur;
    dfs(0, cur);
    return res;
}

int main(){
    auto v = letterCombinations("23");
    cout<<"Combinations:\n"; for(auto &s:v) cout<<s<<" "; cout<<"\n";
    return 0;
}

// Time Complexity: O(4^n)
// Space Complexity: O(n) recursion + output
