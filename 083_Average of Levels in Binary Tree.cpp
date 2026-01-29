// Average of Levels in Binary Tree
// Compute average value for nodes on each level.
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{int val; TreeNode* left; TreeNode* right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {}};

vector<double> averageOfLevels(TreeNode* root){
    vector<double> res;
    if(!root) return res;
    queue<TreeNode*> q; q.push(root);
    while(!q.empty()){
        long long sum=0; int n=q.size();
        for(int i=0;i<n;++i){ TreeNode* t=q.front(); q.pop(); sum+=t->val; if(t->left) q.push(t->left); if(t->right) q.push(t->right); }
        res.push_back((double)sum/n);
    }
    return res;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    auto v = averageOfLevels(root);
    cout<<"Averages: "; for(double d:v) cout<<d<<" "; cout<<"\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
