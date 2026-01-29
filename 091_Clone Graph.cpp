// Clone Graph
// Return a deep copy (clone) of an undirected graph.
// Solution: DFS/BFS with hashmap from old node to copied node.
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node(int _val=0): val(_val) {}
};

Node* cloneGraph(Node* node) {
    if (!node) return nullptr;
    unordered_map<Node*, Node*> m;
    queue<Node*> q; q.push(node);
    m[node] = new Node(node->val);
    while(!q.empty()){
        Node* cur = q.front(); q.pop();
        for(auto nb: cur->neighbors){
            if(!m.count(nb)) { m[nb] = new Node(nb->val); q.push(nb); }
            m[cur]->neighbors.push_back(m[nb]);
        }
    }
    return m[node];
}

int main(){
    // small graph: 1--2
    Node* a = new Node(1); Node* b = new Node(2);
    a->neighbors.push_back(b); b->neighbors.push_back(a);
    Node* c = cloneGraph(a);
    cout<<"Cloned root val: "<< (c?c->val:-1) <<"\n";
    return 0;
}

// Time Complexity: O(N + E)
// Space Complexity: O(N)
