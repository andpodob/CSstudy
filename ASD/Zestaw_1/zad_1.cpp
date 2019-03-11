/*
    Merge sort on linked list with natural series aproach
*/

#include <bits/stdc++.h>

using namespace std;


struct node{
    node* next;
    int key;
};

void print(node* start){
    while(start != nullptr){
        cout<< start->key << " ";
        start = start->next;
    }
    cout<<endl;
}

void add(node* &start, int value){
    node* p = new node;
    if(p == NULL) return;
    p->key = value;
    p->next = start;
    start = p;
}

node* cutOffNaturalSeries(node* &first){
    if(first == NULL) return NULL;
    node* f = first;
    node* temp = first;
    while(temp->next != NULL && temp->key <= temp->next->key){ //going through list while it's increasing in natural way
        temp = temp->next;
    }
    if(temp->next == NULL){ //if we reached end of the list it means it is sorted in natural way
        first = temp->next;
    }else{ //if not, we cut the natural sorted sequence, update first pointer, and return pointer to the part we cut off
        first = temp->next;
        temp->next = NULL;
    }
    return f;
}

node* merge(node* list1, node* list2){
    if(list1 == NULL)return list2;
    if(list2 == NULL)return list1;
    node* head = new node;
    head->next = NULL;
    node* tail = head;

    while(list1 != NULL && list2 != NULL){
        if(list1->key <= list2->key){
            tail->next = list1;
            tail = tail->next;
            list1 = list1->next;
            tail->next = NULL;
        }else{
            tail->next = list2;
            tail = tail->next;
            list2 = list2->next;
            tail->next = NULL;
        }
    }
    if(list1 != NULL){
        tail->next = list1;
    }
    if(list2 != NULL){
        tail->next = list2;
    }

    node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

node* merge_sort(node* first){
    node* head = cutOffNaturalSeries(first);
    while(first != NULL){
        head = merge(head, cutOffNaturalSeries(first));
    }
    return head;
}

int main(){
    node* first = new node;
    first->next = NULL;
    first->key = rand()%1000;
    for(int i = 0; i < 100000; i++){
        add(first, rand()%1000);
    }
    cout<<"start: "<<endl;
    auto start = chrono::high_resolution_clock::now();
    first = merge_sort(first);
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    cout<<"Elapsed time: "<<elapsed.count() << endl;
}