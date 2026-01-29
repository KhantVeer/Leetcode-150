// Sum Root to Leaf Numbers
// Calculate the total of numbers represented by root-to-leaf paths.
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {int val; TreeNode* left; TreeNode* right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {}};

int dfs(TreeNode* node, int cur) {
    if (!node) return 0;
    cur = cur*10 + node->val;
    if (!node->left && !node->right) return cur;
    return dfs(node->left, cur) + dfs(node->right, cur);
}

int sumNumbers(TreeNode* root) {
    return dfs(root,0);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout<<"Sum numbers: "<<sumNumbers(root)<<"\n"; // 12 + 13 =25
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(h)
