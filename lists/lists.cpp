#include "lists.h"
#include <bits/stdc++.h>

ListNode::ListNode(int x){
    this->val = x;
    this->next = NULL;
}

ListNode *createList(vector<int> elements){
    ListNode *start = new ListNode(elements[0]);
    ListNode *end = start;
    for(int i = 1; i < elements.size(); i++){
        end->next = new ListNode(elements[i]);
        end = end->next;
    }
    return start;
}

void printList(ListNode* first){
    while (first != NULL)
    {
        cout<<first->val<<" ";
        first = first->next;
    }
    cout<<endl;
}