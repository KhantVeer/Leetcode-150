// Binary Tree Zigzag Level Order Traversal
// Return zigzag level order traversal (alternating directions per level).
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{int val; TreeNode* left; TreeNode* right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {}};

vector<vector<int>> zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> res;
    if(!root) return res;
    queue<TreeNode*> q; q.push(root);
    bool leftToRight = true;
    while(!q.empty()){
        int n=q.size(); vector<int> row(n);
        for(int i=0;i<n;++i){ TreeNode* t=q.front(); q.pop(); int idx = leftToRight? i : (n-1-i); row[idx]=t->val; if(t->left) q.push(t->left); if(t->right) q.push(t->right);} 
        res.push_back(row);
        leftToRight = !leftToRight;
    }
    return res;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    auto v = zigzagLevelOrder(root);
    cout<<"Zigzag:\n";
    for(auto &r:v){ for(int x:r) cout<<x<<" "; cout<<"\n"; }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
