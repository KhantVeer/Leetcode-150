// Course Schedule
// Determine if all courses can be finished given prerequisites (detect cycle in directed graph).
#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
    vector<vector<int>> g(numCourses);
    vector<int> indeg(numCourses,0);
    for(auto &p: prerequisites){ g[p[1]].push_back(p[0]); indeg[p[0]]++; }
    queue<int> q; for(int i=0;i<numCourses;++i) if(indeg[i]==0) q.push(i);
    int seen=0;
    while(!q.empty()){ int u=q.front(); q.pop(); ++seen; for(int v:g[u]) if(--indeg[v]==0) q.push(v); }
    return seen==numCourses;
}

int main(){
    int n=2; vector<vector<int>> pre={{1,0}};
    cout<<boolalpha<<"Can finish: "<<canFinish(n,pre)<<"\n";
    vector<vector<int>> bad={{1,0},{0,1}};
    cout<<"Can finish (cycle): "<<canFinish(2,bad)<<"\n";
    return 0;
}

// Time Complexity: O(N+E)
// Space Complexity: O(N+E)
