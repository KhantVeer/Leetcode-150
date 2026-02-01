/*
148. Sort List
Sort a linked list in O(n log n) time and constant space (merge sort on linked list).
*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwo(ListNode* l1, ListNode* l2){
    ListNode dummy(0), *p = &dummy;
    while(l1 && l2){
        if(l1->val < l2->val){ p->next = l1; l1 = l1->next; }
        else { p->next = l2; l2 = l2->next; }
        p = p->next;
    }
    p->next = l1 ? l1 : l2;
    return dummy.next;
}

ListNode* sortList(ListNode* head){
    if(!head || !head->next) return head;
    // split list into halves
    ListNode *slow = head, *fast = head, *prev = nullptr;
    while(fast && fast->next){ prev = slow; slow = slow->next; fast = fast->next->next; }
    prev->next = nullptr;
    ListNode* l1 = sortList(head);
    ListNode* l2 = sortList(slow);
    return mergeTwo(l1, l2);
}

ListNode* make_list(const vector<int>& a){
    ListNode dummy(0), *p=&dummy;
    for(int x: a){ p->next = new ListNode(x); p = p->next; }
    return dummy.next;
}

void print_list(ListNode* head){
    for(auto p=head; p; p=p->next) cout << p->val << (p->next?" -> ":"\n");
}

int main(){
    auto l1 = make_list({4,2,1,3});
    cout << "Original: "; print_list(l1);
    auto s1 = sortList(l1);
    cout << "Sorted: "; print_list(s1);

    auto l2 = make_list({-1,5,3,4,0});
    cout << "Original: "; print_list(l2);
    auto s2 = sortList(l2);
    cout << "Sorted: "; print_list(s2);

    return 0;
}

// Time Complexity: O(n log n)
// Space Complexity: O(log n) recursion stack
