#include <bits/stdc++.h>

using namespace std;


 //Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
private:
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
    
    vector<ListNode*> mergeKListsRequ(vector<ListNode*>& lists){
        if(lists.size() == 1) return lists;
        vector<ListNode*> result;
        for(int i = 0; i < lists.size(); i+=2){
            if(i+1 == lists.size())result.push_back(lists[i]);
            else{
                result.push_back(mergeTwoLists(lists[i], lists[i+1]));
            }
        }
        return mergeKListsRequ(result);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)return NULL;
        vector<ListNode*> result = mergeKListsRequ(lists);
        return result[0];
    }
};

ListNode *createList(vector<int> elements){
    if(elements.size() == 0)return NULL;
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
    vector<ListNode*> lists;
    ListNode *first = createList({});
    lists.push_back(first);
    ListNode *second = createList({});
    lists.push_back(second);
    ListNode *third = createList({2,6});
    lists.push_back(third);

    first = s.mergeKLists(lists);
    printList(first);
}