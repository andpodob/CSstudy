#include <bits/stdc++.h>

using namespace std;


 //Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode *start = new ListNode(0);
        ListNode *end = start;
        
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                end->next = l1;
                l1 = l1->next;
            }else{
                end->next = l2;
                l2 = l2->next;
            }
            end = end->next;
        }
        
        if(l1 != NULL) end->next = l1;
        if(l2 != NULL) end->next = l2;
        
        return start->next;
    }
};

ListNode *createList(vector<int> elements){
    ListNode *start = new ListNode(elements[0]);
    ListNode *end = start;
    for(int i = 1; i < elements.size(); i++){
        end->next = new ListNode(elements[i]);
        end = end->next;
    }
    return start;
}

void printList(ListNode *first){
    while (first != NULL)
    {
        cout<<first->val<<" ";
        first = first->next;
    }
    cout<<endl;
}

int main(){
    Solution s;
    ListNode *first = createList({1,2,4});
    ListNode *second = createList({1,3,4});
    first = s.mergeTwoLists(first, second);
    printList(first);
}