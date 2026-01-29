// Minimum Genetic Mutation
// Minimum mutations to change start to end using bank; BFS on words graph.
#include <bits/stdc++.h>
using namespace std;

int minMutation(string start, string end, vector<string>& bank){
    unordered_set<string> bankSet(bank.begin(), bank.end());
    if(!bankSet.count(end)) return -1;
    string chars = "ACGT";
    queue<pair<string,int>> q; q.push({start,0}); unordered_set<string> vis{start};
    while(!q.empty()){
        auto [s,d]=q.front(); q.pop();
        if(s==end) return d;
        string t=s;
        for(int i=0;i<s.size();++i){ char old=t[i];
            for(char c: chars){ if(c==old) continue; t[i]=c; if(bankSet.count(t) && !vis.count(t)){ vis.insert(t); q.push({t,d+1}); }}
            t[i]=old;
        }
    }
    return -1;
}

int main(){
    string start="AACCGGTT", end="AACCGGTA"; vector<string> bank={"AACCGGTA"};
    cout<<"Min mutation: "<<minMutation(start,end,bank)<<"\n";
    return 0;
}

// Time Complexity: O(N * L * 4) where N bank size, L word length
// Space Complexity: O(N)
