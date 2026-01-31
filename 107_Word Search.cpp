// Word Search
// Check if a word exists in a 2D board by DFS/backtracking.
#include <bits/stdc++.h>
using namespace std;

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(); if(m==0) return false; int n = board[0].size();
    function<bool(int,int,int)> dfs = [&](int i, int j, int idx){
        if(idx == word.size()) return true;
        if(i<0 || j<0 || i>=m || j>=n || board[i][j] != word[idx]) return false;
        char tmp = board[i][j]; board[i][j] = '#';
        bool found = dfs(i+1,j,idx+1) || dfs(i-1,j,idx+1) || dfs(i,j+1,idx+1) || dfs(i,j-1,idx+1);
        board[i][j] = tmp;
        return found;
    };
    for(int i=0;i<m;++i) for(int j=0;j<n;++j) if(dfs(i,j,0)) return true;
    return false;
}

int main(){
    vector<vector<char>> b = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout<<boolalpha<<"Word 'ABCCED' exists: "<<exist(b, "ABCCED")<<"\n"; // true
    cout<<"Word 'SEE' exists: "<<exist(b, "SEE")<<"\n"; // true
    cout<<"Word 'ABCB' exists: "<<exist(b, "ABCB")<<"\n"; // false
    return 0;
}

// Time Complexity: O(m*n*4^L) where L is word length
// Space Complexity: O(L) recursion
