// Convert Sorted Array to Binary Search Tree
// Convert a sorted array into a height-balanced BST.
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{int val; TreeNode* left; TreeNode* right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {}};

TreeNode* build(vector<int>& a, int l, int r){
    if(l>r) return nullptr;
    int mid = l + (r-l)/2;
    TreeNode* root = new TreeNode(a[mid]);
    root->left = build(a,l,mid-1);
    root->right = build(a,mid+1,r);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums){
    return build(nums, 0, nums.size()-1);
}

void inorder(TreeNode* r){ if(!r) return; inorder(r->left); cout<<r->val<<" "; inorder(r->right); }

int main(){
    vector<int> a = {-10,-3,0,5,9};
    TreeNode* root = sortedArrayToBST(a);
    cout<<"Inorder of BST: "; inorder(root); cout<<"\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(log n) recursion
