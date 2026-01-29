// Surrounded Regions
// Flip 'O's fully surrounded by 'X' to 'X'. Use boundary-fill to mark safe O's.
#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<char>>& board) {
    if(board.empty()) return;
    int m=board.size(), n=board[0].size();
    function<void(int,int)> dfs = [&](int i,int j){
        if(i<0||j<0||i>=m||j>=n||board[i][j]!='O') return;
        board[i][j] = 'S';
        dfs(i+1,j); dfs(i-1,j); dfs(i,j+1); dfs(i,j-1);
    };
    for(int i=0;i<m;++i){ if(board[i][0]=='O') dfs(i,0); if(board[i][n-1]=='O') dfs(i,n-1); }
    for(int j=0;j<n;++j){ if(board[0][j]=='O') dfs(0,j); if(board[m-1][j]=='O') dfs(m-1,j); }
    for(int i=0;i<m;++i) for(int j=0;j<n;++j){ if(board[i][j]=='O') board[i][j]='X'; else if(board[i][j]=='S') board[i][j]='O'; }
}

int main(){
    vector<vector<char>> b = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    solve(b);
    cout<<"After capture:\n";
    for(auto &row: b){ for(char c: row) cout<<c; cout<<"\n"; }
    return 0;
}

// Time Complexity: O(m*n)
// Space Complexity: O(m*n) recursion
