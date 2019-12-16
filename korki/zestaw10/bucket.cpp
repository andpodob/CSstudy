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

void divide(Node* list,Node* buckets[10]){
    for(int i = 0; i < 10; i++) buckets[i] = NULL;
    
    Node* temp;
    while (list != NULL)
    {   
        temp = list;
        list = list->next;
        temp->next = buckets[temp->val%10];
        buckets[temp->val%10] = temp;
    }
    
}

Node* mergeBuckets(Node* buckets[10]){
    Node* helper = new Node(-1);
    Node* temp = helper;
    for(int i = 0; i < 10; i++){
        temp->next = buckets[i];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
    }
    temp = helper;
    helper = helper->next;
    delete temp;
    return helper;
}

Node* processList(Node* list){
    Node** buckets = new Node*[10];
    divide(list, buckets);
    return mergeBuckets(buckets);
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
    
    addInFront(list1, new Node(rand()%100));
    addInFront(list1, new Node(rand()%100));
    addInFront(list1, new Node(rand()%100));
    addInFront(list1, new Node(rand()%100));
    addInFront(list1, new Node(rand()%100));
    addInFront(list1, new Node(rand()%100));
    addInFront(list1, new Node(rand()%100));
    addInFront(list1, new Node(rand()%100));
    addInFront(list1, new Node(rand()%100));
    addInFront(list1, new Node(rand()%100));

    printList(processList(list1));
}