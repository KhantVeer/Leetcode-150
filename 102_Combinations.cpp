// Combinations
// Return all combinations of k numbers from 1..n.
// Solution: backtracking.
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> combine(int n, int k){
    vector<vector<int>> res; vector<int> cur;
    function<void(int)> dfs = [&](int start){
        if(cur.size()==k){ res.push_back(cur); return; }
        for(int i=start;i<=n;++i){ cur.push_back(i); dfs(i+1); cur.pop_back(); }
    };
    dfs(1);
    return res;
}

int main(){
    auto r = combine(4,2);
    cout<<"Combinations:\n"; for(auto &v:r){ for(int x:v) cout<<x; cout<<"\n"; }
    return 0;
}

// Time Complexity: O(C(n,k) * k)
// Space Complexity: O(k)
