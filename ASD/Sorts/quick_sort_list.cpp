#include <bits/stdc++.h>

using namespace std;

struct node{
    int w;
    node* next = nullptr;
};

void print(node*);
int add(node*&, int);
node* split(node*&);
node* quick_sort(node*);

void print(node* start){
    while(start != NULL){
        cout<< start->w << " ";
        start = start->next;
    }
    cout<<endl;
}

int add(node* &start, int value){
    node* p = new node;
    if(p == NULL) return 1;
    p->w = value;
    p->next = start;
    start = p;
    return 0;
}

node* split(node* &start){
    if(start == nullptr || start->next == nullptr)return nullptr;

    node* temp = start, *temp2;
    int pivot = start->w;
    node* first_head = new node, *second_head = new node, *p ;
    node* first_tail = first_head, *second_tail = second_head;

    while(temp != nullptr){
        temp2 = temp;
        temp = temp->next;
        temp2->next = nullptr;
        if(temp2->w > pivot){
            //przypinam do second
            second_tail->next = temp2;
            second_tail = second_tail->next; 
        }else if(temp2->w < pivot){
            //przypinam do first
            first_tail->next = temp2;
            first_tail = first_tail->next;
        }else{
            p = temp2;
        }
    }
    p->next = nullptr;
    first_tail->next = p;
    first_tail = first_tail->next;

    temp = first_head;
    first_head = first_head->next;
    delete temp;

    temp = second_head;
    second_head = second_head->next;
    delete temp;

    start = first_head;
    return second_head;
}

node* quick_sort(node* start){
    node* first = start, *second, *temp;
    if(start != nullptr && start->next != nullptr){
        second = split(first);
        first = quick_sort(first);
        second = quick_sort(second);
        temp = first;
        while(temp->next != nullptr)temp=temp->next;
        temp->next = second;
        return first;
    }
    return start;
}

int main(){
    node* first = new node, *second;
    first->next = nullptr;
    first->w = 40;
    for(int i = 0; i < 100000000; i++) add(first, rand()%100);
    // print(first);
    // first = quick_sort(first);
    // print(first);

    cout<<"start: "<<endl;
    auto start = chrono::high_resolution_clock::now();
    first = quick_sort(first);
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    cout<<"Elapsed time: "<<elapsed.count() << endl;
}