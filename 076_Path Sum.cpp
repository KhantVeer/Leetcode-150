// Path Sum
// Check if the binary tree has a root-to-leaf path with given sum.
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {int val; TreeNode* left; TreeNode* right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {}};

bool hasPathSum(TreeNode* root, int target) {
    if (!root) return false;
    if (!root->left && !root->right) return root->val == target;
    return hasPathSum(root->left, target - root->val) || hasPathSum(root->right, target - root->val);
}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    cout << boolalpha;
    cout<<"Has path sum 22: "<<hasPathSum(root,22)<<"\n"; // true
    cout<<"Has path sum 26: "<<hasPathSum(root,26)<<"\n"; // true (5+8+13)
    cout<<"Has path sum 18: "<<hasPathSum(root,18)<<"\n"; // false
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(h)
