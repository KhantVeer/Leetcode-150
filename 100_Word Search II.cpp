// Word Search II
// Find all words from dictionary on 2D board using Trie + DFS backtracking.
#include <bits/stdc++.h>
using namespace std;

struct TrieNode{ bool end=false; array<TrieNode*,26> ch{}; string word=""; TrieNode(){ ch.fill(nullptr); }};

void insertTrie(TrieNode* root, const string& w){ TrieNode* p=root; for(char c:w){ int i=c-'a'; if(!p->ch[i]) p->ch[i]=new TrieNode(); p=p->ch[i]; } p->end=true; p->word=w; }

vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
    TrieNode* root = new TrieNode();
    for(auto &w: words) insertTrie(root,w);
    int m=board.size(), n=m?board[0].size():0; vector<string> res; 
    function<void(int,int,TrieNode*)> dfs = [&](int i,int j, TrieNode* node){
        char c=board[i][j]; int idx=c-'a'; TrieNode* nxt = node->ch[idx]; if(!nxt) return;
        if(nxt->end){ res.push_back(nxt->word); nxt->end=false; }
        board[i][j]='#';
        int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        for(auto &d:dirs){ int ni=i+d[0], nj=j+d[1]; if(ni>=0&&ni<m&&nj>=0&&nj<n&&board[ni][nj]!='#') dfs(ni,nj,nxt); }
        board[i][j]=c;
    };
    for(int i=0;i<m;++i) for(int j=0;j<n;++j) dfs(i,j,root);
    return res;
}

int main(){
    vector<vector<char>> b = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> ws = {"oath","pea","eat","rain"};
    auto res = findWords(b, ws);
    cout<<"Found:\n"; for(auto &s:res) cout<<s<<"\n";
    return 0;
}

// Time Complexity: O(M*N*4^L) worst-case (pruned by trie)
// Space Complexity: O(sum words length)
