// Design Add and Search Words Data Structure
// Support addWord and search with '.' wildcard using Trie + DFS.
#include <bits/stdc++.h>
using namespace std;

struct Node{ bool end=false; array<Node*,26> ch{}; Node(){ ch.fill(nullptr);} };

class WordDictionary{
    Node* root;
public:
    WordDictionary(): root(new Node()){}
    void addWord(const string& w){ Node* p=root; for(char c:w){ int i=c-'a'; if(!p->ch[i]) p->ch[i]=new Node(); p=p->ch[i]; } p->end=true; }
    bool dfs(const string& w, int idx, Node* p){
        if(!p) return false;
        if(idx==w.size()) return p->end;
        if(w[idx]=='.'){
            for(auto nxt: p->ch) if(nxt && dfs(w, idx+1, nxt)) return true;
            return false;
        } else {
            int i=w[idx]-'a'; return dfs(w, idx+1, p->ch[i]);
        }
    }
    bool search(const string& w){ return dfs(w,0,root); }
};

int main(){
    WordDictionary wd; wd.addWord("bad"); wd.addWord("dad"); wd.addWord("mad");
    cout<<boolalpha<<wd.search("pad")<<" "<<wd.search("bad")<<" "<<wd.search(".ad")<<" "<<wd.search("b..")<<"\n";
    return 0;
}

// Time Complexity: add O(L), search worst-case O(26^L) with wildcards but typically O(L * branching)
// Space Complexity: O(total chars)
