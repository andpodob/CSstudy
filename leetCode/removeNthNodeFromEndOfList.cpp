#include <bits/stdc++.h>

using namespace std;


 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* a = head;
        ListNode* b = head;
        int i = 0;
        for(i = 0; i < n && a != NULL; i++){
            a = a->next;
        }
        if(a == NULL && i <= n)return head->next;
        a = a->next;
        while(a != NULL){
            a = a->next;
            b = b->next;
        }
        a = b->next;
        b->next = b->next->next;
        delete a;
        return head;
    }
};

int main(){
    ListNode *l = new ListNode(3);
    Solution s;
    cout<<s.removeNthFromEnd(l, 1)<<endl;
}