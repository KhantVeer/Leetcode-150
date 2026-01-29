// Evaluate Division
// Given ratios, answer division queries using graph and DFS/BFS (weighted edges).
#include <bits/stdc++.h>
using namespace std;

double dfs(unordered_map<string, vector<pair<string,double>>>& g, const string& s, const string& t, unordered_set<string>& vis){
    if(!g.count(s) || !g.count(t)) return -1.0;
    if(s==t) return 1.0;
    vis.insert(s);
    for(auto &p: g[s]){
        if(vis.count(p.first)) continue;
        double r = dfs(g, p.first, t, vis);
        if(r>0) return p.second * r;
    }
    return -1.0;
}

vector<double> calcEquation(vector<vector<string>>& eqs, vector<double>& vals, vector<vector<string>>& queries){
    unordered_map<string, vector<pair<string,double>>> g;
    for(size_t i=0;i<eqs.size();++i){ auto &e=eqs[i]; g[e[0]].push_back({e[1], vals[i]}); g[e[1]].push_back({e[0], 1.0/vals[i]}); }
    vector<double> res;
    for(auto &q: queries){ unordered_set<string> vis; res.push_back(dfs(g,q[0],q[1],vis)); }
    return res;
}

int main(){
    vector<vector<string>> eqs = {{"a","b"},{"b","c"}};
    vector<double> vals = {2.0,3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"}};
    auto r = calcEquation(eqs, vals, queries);
    cout<<"Results:\n"; for(double d: r) cout<<d<<"\n";
    return 0;
}

// Time Complexity: O(Q * (V+E)) worst-case
// Space Complexity: O(V+E)
