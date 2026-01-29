// Minimum Absolute Difference in BST
// Find min absolute difference between values of any two nodes in a BST.
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{int val; TreeNode* left; TreeNode* right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {}};

int getMinimumDifference(TreeNode* root){
    int prev = INT_MIN; bool hasPrev=false; int best = INT_MAX;
    function<void(TreeNode*)> dfs = [&](TreeNode* node){
        if(!node) return;
        dfs(node->left);
        if(hasPrev) best = min(best, abs(node->val - prev)); else hasPrev = true;
        prev = node->val;
        dfs(node->right);
    };
    dfs(root);
    return best==INT_MAX?0:best;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    cout<<"Min abs diff: "<<getMinimumDifference(root)<<"\n"; // 1
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(h)
