#include <bits/stdc++.h>

using namespace std;

/*
    Here is simple implementation of selection sort on one-way linked list;
*/


struct node{
    int w;
    node* next;
};

void print(node*);

int add(node* &start, int value){
    node* p = new node;
    if(p == NULL) return 1;
    p->w = value;
    p->next = start;
    start = p;
    return 0;
}

node* cut_min(node *first){
    node *current_prev = first;
    node *current = first->next; 
    node *max = first->next;
    node *max_prev = first;
    //znajdowanie maxa
    while(current != NULL){
        if(current->w < max->w){
            max = current;
            max_prev = current_prev;
        }
        current_prev = current_prev->next;
        current = current->next;
    }
    //wycinanie maxa
    max_prev->next = (max != NULL)?max->next:NULL;
    if(max != NULL)max->next = NULL;
    return max;
}


node* selection_sort(node* first){
    node* f = new node;
    f->next = first; //wstawiam wartownika;
    node* sorted = cut_min(f);
    node* current = sorted;
    while(current != NULL){
        current->next = cut_min(f);
        current = current->next;
    }
    delete f;
    return sorted;
}

void print(node* start){
    while(start != NULL){
        cout<< start->w << " ";
        start = start->next;
    }
    cout<<endl;
}

int main(){
    node* first = new node;
    first->next = NULL;
    first->w = rand()%1000;
    for(int i = 0; i < 10000000; i++){
        add(first, rand()%1000);
    }
    cout<<"start: "<<endl;
    auto start = chrono::high_resolution_clock::now();
    first = selection_sort(first);
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    cout<<"Elapsed time: "<<elapsed.count() << endl;
}