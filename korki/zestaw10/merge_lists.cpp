#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

Node* mergeRequ(Node* first, Node* second){
    if(first == NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }
    Node* result;
    if(first->val < second->val){
        result = first;
        first = first->next;
    }else{
        result = second;
        second = second->next;
    }
    result->next = mergeRequ(first, second);

    return result;
}

Node* mergeIter(Node* first, Node* second){
    Node* mergedList = new Node(-1);
    Node* temp = mergedList;

    while(first != NULL and second != NULL){
        if(first->val <= second->val){
            temp->next = first;
            first = first->next;
        }else{
            temp->next = second;
            second = second->next;
        }
        temp = temp->next;
    }
    if(first != NULL){
        temp->next = first;
    }
    if(second != NULL){
        temp->next = second;
    }

    Node* czyszczenie = mergedList;
    mergedList = mergedList->next;
    delete czyszczenie;

    return mergedList;
}

void addInFront(Node*& list, Node* element){
    element->next = list;
    list = element;
}

void printList(Node* begin){
    while(begin != NULL){
        cout<<begin->val<<" ";
        begin = begin->next;
    }
    cout<<endl;
}

int main(){
    Node* list1 = NULL;
    Node* list2 = NULL;
    
    addInFront(list1, new Node(7));
    addInFront(list1, new Node(6));
    addInFront(list1, new Node(3));
    addInFront(list1, new Node(1));
    addInFront(list1, new Node(0));

    addInFront(list2, new Node(9));
    addInFront(list2, new Node(5));
    addInFront(list2, new Node(4));
    addInFront(list2, new Node(2));
    addInFront(list2, new Node(1));

    printList(list1);
    printList(list2);

    Node *merged = mergeRequ(list1, list2);

    printList(merged);
}