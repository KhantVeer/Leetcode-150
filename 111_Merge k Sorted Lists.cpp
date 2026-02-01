// Merge k Sorted Lists
// Merge k sorted linked lists into one sorted list using a min-heap.
#include <bits/stdc++.h>
using namespace std;
struct ListNode{int val; ListNode* next; ListNode(int x): val(x), next(nullptr) {}};

struct Cmp{ bool operator()(ListNode* a, ListNode* b) const { return a->val > b->val; } };

ListNode* mergeKLists(vector<ListNode*>& lists){
    priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;
    for(auto p: lists) if(p) pq.push(p);
    ListNode dummy(0), *tail=&dummy;
    while(!pq.empty()){
        auto node = pq.top(); pq.pop(); tail->next = node; tail = tail->next;
        if(node->next) pq.push(node->next);
    }
    return dummy.next;
}

int main(){
    // build small lists: [1->4->5], [1->3->4], [2->6]
    ListNode* a = new ListNode(1); a->next=new ListNode(4); a->next->next=new ListNode(5);
    ListNode* b = new ListNode(1); b->next=new ListNode(3); b->next->next=new ListNode(4);
    ListNode* c = new ListNode(2); c->next=new ListNode(6);
    vector<ListNode*> lists = {a,b,c};
    ListNode* res = mergeKLists(lists);
    cout<<"Merged: "; while(res){ cout<<res->val<<" "; res = res->next; } cout<<"\n";
    return 0;
}

// Time Complexity: O(N log k) where N total nodes, k lists
// Space Complexity: O(k)
