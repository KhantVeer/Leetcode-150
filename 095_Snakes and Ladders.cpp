// Snakes and Ladders
// Minimum moves to reach final square on board with snakes and ladders using BFS.
#include <bits/stdc++.h>
using namespace std;

int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<int> cells(n*n+1);
    int idx=1; int r=n-1,c=0; int dir=1;
    for(int i=n-1;i>=0;--i){ // convert board to 1D
        for(int j=0;j<n;++j){ int col = (dir==1? j: n-1-j); cells[idx++] = board[i][col]; }
        dir *= -1;
    }
    vector<int> dist(n*n+1, -1); queue<int> q; dist[1]=0; q.push(1);
    while(!q.empty()){
        int u=q.front(); q.pop();
        if(u==n*n) return dist[u];
        for(int d=1; d<=6 && u+d<=n*n; ++d){
            int v = u+d; if(cells[v]!=-1) v = cells[v];
            if(dist[v]==-1){ dist[v]=dist[u]+1; q.push(v); }
        }
    }
    return -1;
}

int main(){
    vector<vector<int>> b = {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
    cout<<"Min moves: "<<snakesAndLadders(b)<<"\n";
    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
