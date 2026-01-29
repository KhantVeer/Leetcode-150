// Binary Tree Maximum Path Sum
// Find maximum sum of any path in a binary tree (path can start and end anywhere).
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{int val; TreeNode* left; TreeNode* right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {}};

class Solution {
public:
    int best = INT_MIN;
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int L = max(0, dfs(node->left));
        int R = max(0, dfs(node->right));
        best = max(best, node->val + L + R);
        return node->val + max(L,R);
    }
    int maxPathSum(TreeNode* root) { dfs(root); return best; }
};

int main(){
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout<<"Max path sum: "<<Solution().maxPathSum(root)<<"\n"; // 42
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(h)
