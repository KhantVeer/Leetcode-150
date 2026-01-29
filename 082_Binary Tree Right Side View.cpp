// Binary Tree Right Side View
// Return values seen from the right side, level by level.
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{int val; TreeNode* left; TreeNode* right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {}};

vector<int> rightSideView(TreeNode* root){
    vector<int> res;
    if (!root) return res;
    queue<TreeNode*> q; q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;++i){
            TreeNode* t=q.front(); q.pop();
            if(i==n-1) res.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
    }
    return res;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    auto v = rightSideView(root);
    cout<<"Right side view: "; for(int x:v) cout<<x<<" "; cout<<"\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
