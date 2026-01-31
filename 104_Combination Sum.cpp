// Combination Sum
// Find all unique combinations where numbers can be reused to reach target.
// Solution: backtracking sorted candidates.
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res; vector<int> cur;
    function<void(int,int)> dfs = [&](int idx, int remain){
        if(remain==0){ res.push_back(cur); return; }
        for(int i=idx;i<candidates.size() && candidates[i]<=remain;++i){ cur.push_back(candidates[i]); dfs(i, remain-candidates[i]); cur.pop_back(); }
    };
    dfs(0, target);
    return res;
}

int main(){
    vector<int> c = {2,3,6,7}; int t = 7;
    auto r = combinationSum(c,t);
    cout<<"Combination Sum results:\n"; for(auto &v:r){ for(int x:v) cout<<x<<" "; cout<<"\n"; }
    return 0;
}

// Time Complexity: Exponential
// Space Complexity: O(target/min(candidates)) recursion
