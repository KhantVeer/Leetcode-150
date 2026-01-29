// Number of Islands
// Count number of islands in a grid of '1' and '0' using DFS/BFS.
#include <bits/stdc++.h>
using namespace std;

int numIslands(vector<vector<char>>& grid) {
    if(grid.empty()) return 0;
    int m=grid.size(), n=grid[0].size();
    int cnt=0;
    function<void(int,int)> dfs = [&](int i,int j){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]!='1') return;
        grid[i][j]='0';
        dfs(i+1,j); dfs(i-1,j); dfs(i,j+1); dfs(i,j-1);
    };
    for(int i=0;i<m;++i) for(int j=0;j<n;++j) if(grid[i][j]=='1'){ ++cnt; dfs(i,j); }
    return cnt;
}

int main(){
    vector<vector<char>> g = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    cout<<"Number of islands: "<<numIslands(g)<<"\n"; // 3
    return 0;
}

// Time Complexity: O(m*n)
// Space Complexity: O(m*n) recursion in worst case
