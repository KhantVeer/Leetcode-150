// Binary Tree Level Order Traversal
// Return BFS level order traversal of a binary tree.
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{int val; TreeNode* left; TreeNode* right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {}};

vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> res;
    if(!root) return res;
    queue<TreeNode*> q; q.push(root);
    while(!q.empty()){
        int n=q.size(); vector<int> row;
        for(int i=0;i<n;++i){ TreeNode* t=q.front(); q.pop(); row.push_back(t->val); if(t->left) q.push(t->left); if(t->right) q.push(t->right);} 
        res.push_back(row);
    }
    return res;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    auto v = levelOrder(root);
    cout<<"Levels:\n";
    for(auto &row:v){ for(int x:row) cout<<x<<" "; cout<<"\n"; }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
