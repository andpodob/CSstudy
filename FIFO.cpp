#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node *next;
};

struct FIFO{
    Node *first;
    Node *last;
    int size;
};

void put(FIFO *queue, Node* x){
    if(queue->size == 0){
        queue->first = queue->last = x;
    }
    else{
        queue->last->next = x;
        queue->last = x;
    }
    queue->size++;
    x->next = NULL;
}

int get(FIFO *queue){
    if(queue->size != 0){
        int val = queue->first->val;
        Node* temp = queue->first;
        queue->first = queue->first->next;
        queue->size--;
        delete temp;
        return val;
    }else{
        cout<<"Queue is empty!"<<endl;
        return -1;
    }
}

void print(FIFO *q){
    Node *temp = q->first;
    while(temp != q->last){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<temp->val<<endl;
}

int main(){
    FIFO *q = new FIFO;
    q->first = NULL;
    q->last = NULL;
    q->size = 0;
    Node *temp;
    for(int i = 1; i <= 10; i++){
        temp = new Node;
        temp->val = i;
        put(q,temp);
    }

    while(q->size != 5){
        cout<<get(q)<<" ";
    }

    cout<<endl;

    for(int i = 100; i <= 120; i++){
        temp = new Node;
        temp->val = i;
        put(q,temp);
    }

    while(q->size != 0){
        cout<<get(q)<<" ";
    }

    cout<<endl;
}