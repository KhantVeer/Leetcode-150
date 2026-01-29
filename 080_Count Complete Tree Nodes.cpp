// Count Complete Tree Nodes
// Count nodes in a complete binary tree in faster than O(n) by comparing subtree heights.
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{int val; TreeNode* left; TreeNode* right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {}};

int heightLeft(TreeNode* node) { int h=0; while(node){ ++h; node = node->left; } return h; }
int heightRight(TreeNode* node) { int h=0; while(node){ ++h; node = node->right; } return h; }

int countNodes(TreeNode* root) {
    if (!root) return 0;
    int hl = heightLeft(root);
    int hr = heightRight(root);
    if (hl==hr) return (1<<hl) - 1; // perfect tree
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    cout<<"Count nodes: "<<countNodes(root)<<"\n"; // 6
    return 0;
}

// Time Complexity: O((log n)^2)
// Space Complexity: O(log n) recursion
