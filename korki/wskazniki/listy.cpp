#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node* next;

    Node(int v){
        this->val = v;
    }
};


void addInFront(Node** list, Node* element){
    element->next = *list;
    *list = element;
}

void printList(Node* begin){
    while(begin != NULL){
        cout<<begin->val<<" ";
        begin = begin->next;
    }
    cout<<endl;
}

int main(){
    Node* node = new Node(5);
    cout<<node<<endl;

    node->val = 4;
    cout<<(*node).val<<endl;

    Node *list = NULL;
    printList(list);
    addInFront(&list, new Node(4));
    printList(list);
    addInFront(&list, new Node(4));
    addInFront(&list, new Node(2));
    addInFront(&list, new Node(3));
    printList(list);
}