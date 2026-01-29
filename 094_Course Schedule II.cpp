// Course Schedule II
// Return a valid course order using topological sort (Kahn). Return empty if impossible.
#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
    vector<vector<int>> g(numCourses);
    vector<int> indeg(numCourses,0);
    for(auto &p: prerequisites){ g[p[1]].push_back(p[0]); indeg[p[0]]++; }
    queue<int> q; for(int i=0;i<numCourses;++i) if(indeg[i]==0) q.push(i);
    vector<int> order;
    while(!q.empty()){ int u=q.front(); q.pop(); order.push_back(u); for(int v:g[u]) if(--indeg[v]==0) q.push(v); }
    if((int)order.size()!=numCourses) return {};
    return order;
}

int main(){
    int n=4; vector<vector<int>> pre={{1,0},{2,0},{3,1},{3,2}};
    auto ord = findOrder(n, pre);
    cout<<"Order: "; for(int x:ord) cout<<x<<" "; cout<<"\n";
    return 0;
}

// Time Complexity: O(N+E)
// Space Complexity: O(N+E)
