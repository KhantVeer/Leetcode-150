// Construct Quad Tree
// Build a QuadTree from a 2D grid: if all values in region equal, make leaf node.
// Solution: recursive divide and conquer.
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    Node(): val(false), isLeaf(false), topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr), bottomRight(nullptr) {}
    Node(bool _val, bool _isLeaf): val(_val), isLeaf(_isLeaf), topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr), bottomRight(nullptr) {}
};

Node* build(const vector<vector<int>>& grid, int r0, int c0, int size){
    if(size==1) return new Node(grid[r0][c0]==1, true);
    int half = size/2;
    Node* tl = build(grid, r0, c0, half);
    Node* tr = build(grid, r0, c0+half, half);
    Node* bl = build(grid, r0+half, c0, half);
    Node* br = build(grid, r0+half, c0+half, half);
    if(tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf && tl->val==tr->val && tl->val==bl->val && tl->val==br->val){
        bool v = tl->val; delete tl; delete tr; delete bl; delete br; return new Node(v, true);
    }
    Node* root = new Node(false, false);
    root->topLeft = tl; root->topRight = tr; root->bottomLeft = bl; root->bottomRight = br;
    return root;
}

Node* constructQuadTree(const vector<vector<int>>& grid){
    int n = grid.size(); if(n==0) return nullptr; return build(grid,0,0,n);
}

int main(){
    vector<vector<int>> g = {{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0}};
    Node* root = constructQuadTree(g);
    cout<<"Constructed quad tree root isLeaf: "<<root->isLeaf<<" val:"<<root->val<<"\n";
    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(n^2) recursion
