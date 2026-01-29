// Validate Binary Search Tree
// Determine if a binary tree is a valid BST.
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{long long val; TreeNode* left; TreeNode* right; TreeNode(long long x): val(x), left(nullptr), right(nullptr) {}};

bool isValidBST(TreeNode* root, long long low=LLONG_MIN, long long high=LLONG_MAX){
    if(!root) return true;
    if(root->val<=low || root->val>=high) return false;
    return isValidBST(root->left, low, root->val) && isValidBST(root->right, root->val, high);
}

int main(){
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout<<boolalpha<<"Is valid BST: "<<isValidBST(root)<<"\n";
    TreeNode* bad = new TreeNode(5);
    bad->left = new TreeNode(1);
    bad->right = new TreeNode(4);
    bad->right->left = new TreeNode(3);
    bad->right->right = new TreeNode(6);
    cout<<"Is valid BST: "<<isValidBST(bad)<<"\n"; // false
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(h)
