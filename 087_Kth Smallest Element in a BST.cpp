// Kth Smallest Element in a BST
// Find the k-th smallest element using iterative inorder traversal.
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{int val; TreeNode* left; TreeNode* right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {}};

int kthSmallest(TreeNode* root, int k){
    stack<TreeNode*> st; TreeNode* cur = root;
    while(cur || !st.empty()){
        while(cur){ st.push(cur); cur=cur->left; }
        cur = st.top(); st.pop();
        if(--k==0) return cur->val;
        cur = cur->right;
    }
    return -1;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    cout<<"kth smallest (k=1): "<<kthSmallest(root,1)<<"\n"; //1
    cout<<"kth smallest (k=3): "<<kthSmallest(root,3)<<"\n"; //3
    return 0;
}

// Time Complexity: O(h + k)
// Space Complexity: O(h)
