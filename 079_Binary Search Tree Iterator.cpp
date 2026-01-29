// Binary Search Tree Iterator
// Implement an iterator over a BST that returns the next smallest element (in-order).
// Solution: use an explicit stack to simulate DFS in-order traversal.
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {int val; TreeNode* left; TreeNode* right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {}};

class BSTIterator {
    stack<TreeNode*> st;
    void pushLeft(TreeNode* node){ while(node){ st.push(node); node=node->left; } }
public:
    BSTIterator(TreeNode* root){ pushLeft(root); }
    int next(){ TreeNode* t = st.top(); st.pop(); int res = t->val; pushLeft(t->right); return res; }
    bool hasNext(){ return !st.empty(); }
};

int main(){
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    BSTIterator it(root);
    cout<<it.next()<<"\n"; // 3
    cout<<it.next()<<"\n"; // 7
    cout<<it.hasNext()<<"\n"; // true
    cout<<it.next()<<"\n"; // 9
    cout<<it.hasNext()<<"\n"; // true
    return 0;
}

// Time Complexity: next() amortized O(1), hasNext() O(1)
// Space Complexity: O(h)
