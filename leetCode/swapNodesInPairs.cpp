#include <bits/stdc++.h>
#include "../lists/lists.h"

using namespace std;

class Solution {
private:
    void swapWithNext(ListNode *node){
        ListNode* temp = node->next;
        node->next = temp->next;
        temp->next = node;
    }
    bool swapTwoNext(ListNode *node){
        if(node == NULL || node->next == NULL || node->next->next == NULL) return false;
        ListNode *temp = node->next->next;
        node->next = temp;
        swapWithNext(node->next);
        return true;
    }

public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* start = head->next;
        swapWithNext(head);
        while(swapTwoNext(head)){
            head = head->next->next;
        }
        return start;
    }
};

int main(){
    vector<int> vec = {1,2,3,4};
    ListNode* testList = createList(vec);
    printList(testList);
}