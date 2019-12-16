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

void removeLongestIncSubs(Node*& list){
    int MAX = 0, counter = 0;
    Node* maxBegin;
    Node* begin = list;
    bool del = false;

    while (list != NULL)
    {   
        counter++;
        if(list->next != NULL and list->next->val > list->val){
            continue;
        }else{
            if(counter > MAX){
                MAX = counter;
                maxBegin = begin;
                del = true;
            }
            if(counter == MAX){
                del = false;
            }
            begin = list->next;
            counter = 0;
        }
        list = list->next;
    }
    if(del){   
        Node* helper = new Node(-1);
        helper->next = list;
        Node* temp = helper;
        while (temp->next != maxBegin)
        {
            temp = temp->next;
        }
    
        Node* temp2 = maxBegin;
        for(int i = 0; i < MAX-1; i++){
            temp2 = temp2->next;
        }
    
        temp->next = temp2->next;
        temp2->next = NULL;

        while (maxBegin != NULL)
        {
            temp = maxBegin;
            maxBegin = maxBegin->next;
            delete temp;
        }

        list = helper->next;
        delete helper;
    }    
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

    //printList(processList(list1));
}