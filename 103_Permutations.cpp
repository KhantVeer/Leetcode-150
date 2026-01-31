// Permutations
// Return all permutations of a list of distinct integers.
// Solution: backtracking with swapping.
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> res;
    function<void(int)> dfs = [&](int i){
        if(i==nums.size()){ res.push_back(nums); return; }
        for(int j=i;j<nums.size();++j){ swap(nums[i], nums[j]); dfs(i+1); swap(nums[i], nums[j]); }
    };
    dfs(0);
    return res;
}

int main(){
    vector<int> a = {1,2,3};
    auto r = permute(a);
    cout<<"Permutations:\n"; for(auto &v:r){ for(int x:v) cout<<x; cout<<"\n"; }
    return 0;
}

// Time Complexity: O(n * n!)
// Space Complexity: O(n)
