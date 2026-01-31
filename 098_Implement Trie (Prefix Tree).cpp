// Implement Trie (Prefix Tree)
// Insert, search and startsWith operations.
#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool end=false; array<TrieNode*,26> ch{}; TrieNode(){ ch.fill(nullptr); }
};

class Trie {
    TrieNode* root;
public:
    Trie(): root(new TrieNode()){}
    void insert(const string& w){ TrieNode* p=root; for(char c:w){ int i=c-'a'; if(!p->ch[i]) p->ch[i]=new TrieNode(); p=p->ch[i]; } p->end=true; }
    bool search(const string& w){ TrieNode* p=root; for(char c:w){ int i=c-'a'; if(!p->ch[i]) return false; p=p->ch[i]; } return p->end; }
    bool startsWith(const string& pfx){ TrieNode* p=root; for(char c:pfx){ int i=c-'a'; if(!p->ch[i]) return false; p=p->ch[i]; } return true; }
};

int main(){
    Trie t; t.insert("apple"); cout<<boolalpha<<t.search("apple")<<" "<<t.search("app")<<" "<<t.startsWith("app")<<"\n";
    t.insert("app"); cout<<t.search("app")<<"\n";
    return 0;
}

// Time Complexity: insert/search/prefix O(L)
// Space Complexity: O(total chars)
