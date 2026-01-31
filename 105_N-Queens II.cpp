// N-Queens II
// Count number of distinct solutions to N-Queens using backtracking with bitmasks.
#include <bits/stdc++.h>
using namespace std;

int totalNQueens(int n){
    int count=0;
    function<void(int,int,int,int)> dfs = [&](int row, int cols, int diags, int anti){
        if(row==n){ ++count; return; }
        int avail = ((1<<n)-1) & ~(cols|diags|anti);
        while(avail){ int bit = avail & -avail; avail -= bit; dfs(row+1, cols|bit, (diags|bit)<<1, (anti|bit)>>1); }
    };
    dfs(0,0,0,0);
    return count;
}

int main(){
    cout<<"N-Queens n=4 solutions: "<<totalNQueens(4)<<"\n"; // 2
    cout<<"N-Queens n=8 solutions: "<<totalNQueens(8)<<"\n";
    return 0;
}

// Time Complexity: roughly O(N!) but pruned
// Space Complexity: O(N)
