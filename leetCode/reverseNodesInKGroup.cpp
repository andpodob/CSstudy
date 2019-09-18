#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    bool checkIfListIsKElement(ListNode* head, int k){
        for(int i = 0 ; i < k-1 && head != NULL; i++){
            head = head->next;
        }
        if(head == NULL) return false;
        return true;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *list = new ListNode(0);
        ListNode *newHead = list;
        ListNode *tail, *temp;
        while(checkIfListIsKElement(head, k)){
            tail = head;
            for(int i = 0; i < k; i++){
                temp = head;
                head = head->next;
                temp->next = list->next;
                list->next = temp;   
            }
            list = tail;
        }
        tail->next = head;
        return newHead->next;
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

void printList(ListNode* first){
    while (first != NULL)
    {
        cout<<first->val<<" ";
        first = first->next;
    }
    cout<<endl;
}

int main(){
    Solution s;
    ListNode *list = createList({});
    printList(list);
    list = s.reverseKGroup(list, 3);
    printList(list);
}