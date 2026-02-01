// Sort List
// Sort a linked list in O(n log n) time using merge sort on lists.
#include <bits/stdc++.h>
using namespace std;
struct ListNode{int val; ListNode* next; ListNode(int x): val(x), next(nullptr) {}};

ListNode* merge(ListNode* a, ListNode* b){
    ListNode dummy(0), *p = &dummy;
    while(a && b){ if(a->val < b->val){ p->next = a; a = a->next; } else { p->next = b; b = b->next; } p = p->next; }
    p->next = a ? a : b; return dummy.next;
}

ListNode* sortList(ListNode* head){
    if(!head || !head->next) return head;
    ListNode *slow = head, *fast = head->next;
    while(fast && fast->next){ slow = slow->next; fast = fast->next->next; }
    ListNode* mid = slow->next; slow->next = nullptr;
    ListNode* l = sortList(head); ListNode* r = sortList(mid);
    return merge(l,r);
}

int main(){
    ListNode* a = new ListNode(4); a->next = new ListNode(2); a->next->next = new ListNode(1); a->next->next->next = new ListNode(3);
    ListNode* s = sortList(a);
    cout<<"Sorted list: "; while(s){ cout<<s->val<<" "; s = s->next; } cout<<"\n";
    return 0;
}

// Time Complexity: O(n log n)
// Space Complexity: O(log n) recursion
