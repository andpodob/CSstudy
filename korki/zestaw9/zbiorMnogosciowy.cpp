#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node* next;
};

bool exists(Node* head, int val){
    while (head != NULL and head->val != val)
    {
        head = head->next;
    }
    if(head == NULL) return false;
    else return true;
}

void add(Node** head, int val){
    if(!exists(*head, val)){
        Node* newNode = new Node;
        newNode->val = val;
        newNode->next = *head;
        *head = newNode;
    }
}

void remove(Node** head, int val){
    Node* temp = *head;
    if(exists(*head, val)){
        if((*head)->val == val){
            *head = (*head)->next;
            delete temp;
        }else{
            while (temp->next->val != val)
            {
                temp = temp->next;
            }
            Node* temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
        }
    }
    
}

void printList(Node* begin){
    while(begin != NULL){
        cout<<begin->val<<" ";
        begin = begin->next;
    }
    cout<<endl;
}

int main(){
    Node* node = NULL;
    add(&node, 5);
    add(&node, 6);
    printList(node);

    cout<<exists(node, 6)<<endl;
    cout<<exists(node, 9)<<endl;

    remove(&node, 5);
    printList(node);
    remove(&node, 9);
    printList(node);
    remove(&node, 6);
    printList(node);
    remove(&node, 6);
    printList(node);
}