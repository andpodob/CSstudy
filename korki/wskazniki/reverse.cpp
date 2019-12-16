#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node* next;
};

Node* reverse(Node* list){
    Node* newList = new Node;
    Node* temp;
    while(list != NULL){
        temp = list;
        list = list->next;
        temp->next = newList->next;
        newList->next = temp; 
    }
    temp = newList;
    newList = newList->next;
    delete temp;
    return newList;
}

void printList(Node* begin){
    while(begin != NULL){
        cout<<begin->val<<" ";
        begin = begin->next;
    }
    cout<<endl;
}

int main(){
    
}