#include <bits/stdc++.h>

using namespace std;

struct Node{
    double w;
    Node* next;
};

int length(Node*);
void Sort(Node*);
void sortedInsert(Node*, Node*);
void insertion_Sort(Node*&);

int length(Node *list){
    int counter = 0;
    while(list->next != NULL){
        counter++;
        list = list->next;
    }
    return counter;
}

void Sort(Node* list){
    int temp, N;
    Node *x, *tail;
    N = length(list);
    Node* buckets[N];
    for(int i = 0; i < N; i++)buckets[i] = new Node;
    while(list->next != NULL){
        temp = N*(list->next->w/10);
        x = list->next;
        list->next = list->next->next;
        x->next = buckets[temp]->next;
        buckets[temp]->next = x;
    }
    for(int i = 0; i < N; i++)insertion_Sort(buckets[i]);
    tail = list;
    for(int i = 0; i < N; i++){
        while(buckets[i]->next != NULL){
            x = buckets[i]->next;
            buckets[i]->next = buckets[i]->next->next;
            x->next = NULL;
            tail->next = x;
            tail = tail->next;
        }
    }
}

void sortedInsert(Node* list, Node* new_node){
    Node* current = list;
    while(current->next != NULL && current->next->w < new_node->w){
        current=current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}

void insertionSort(Node* &list){
    Node* sorted, *current, *next;
    sortedInsert(sorted,list->next);
    list->next = list->next->next;
    current = list->next;
    while(current != NULL){
        next = current->next;
        sortedInsert(sorted, current);
        current = next;
    }
    list = sorted;
}


int main(){
    
}