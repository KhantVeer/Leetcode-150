// Word Ladder
// Shortest transformation sequence length using BFS on word graph.
#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList){
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if(!dict.count(endWord)) return 0;
    queue<pair<string,int>> q; q.push({beginWord,1}); unordered_set<string> vis{beginWord};
    while(!q.empty()){
        auto [w,d]=q.front(); q.pop();
        if(w==endWord) return d;
        string t=w;
        for(int i=0;i<w.size();++i){ char old=t[i];
            for(char c='a';c<='z';++c){ if(c==old) continue; t[i]=c; if(dict.count(t) && !vis.count(t)){ vis.insert(t); q.push({t,d+1}); }}
            t[i]=old;
        }
    }
    return 0;
}

int main(){
    string begin="hit", end="cog"; vector<string> wl={"hot","dot","dog","lot","log","cog"};
    cout<<"Ladder length: "<<ladderLength(begin,end,wl)<<"\n"; // 5
    return 0;
}

// Time Complexity: O(M * N * 26) M word length, N words
// Space Complexity: O(N)
