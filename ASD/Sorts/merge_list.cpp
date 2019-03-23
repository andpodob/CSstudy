#include <bits/stdc++.h>

using namespace std;

struct node{
    int w;
    node* next;
};

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

node* merge(node* l, node* r){
    node *head;
    node *tail;
    node *temp;
    if(l->w < r->w){
        temp = l;
        l = l->next;
        temp->next = NULL;
        head = temp;
    }else{
        temp = r;
        r = r->next;
        temp->next = NULL;
        head = temp;
    }
    tail = head;
    while(l != NULL || r != NULL){
        if(l == NULL){
            temp=r;
            r=r->next;
            temp->next = NULL;
            tail->next = temp;
            tail = tail->next;
        }else if(r == NULL){
            temp=l;
            l=l->next;
            temp->next = NULL;
            tail->next = temp;
            tail = tail->next;
        }else if(l->w < r->w){
            temp=l;
            l=l->next;
            temp->next = NULL;
            tail->next = temp;
            tail = tail->next;
        }else{
            temp=r;
            r=r->next;
            temp->next = NULL;
            tail->next = temp;
            tail = tail->next;
        }
    }
    return head;
}


node* merge_sort(node *start){
    if(start->next == NULL) return start;
    else{
        node *l, *r, *s;
        l = start;
        s = start;
        r = start->next;

        while(r != NULL && r->next != NULL){
            s = s->next;
            r = r->next->next;
        }
        r=s->next;
        s->next = NULL;

        l = merge_sort(l);
        r = merge_sort(r);
        l = merge(l,r);
        return l;
   }    

}


int main(){
    node* first = new node;
    first->next = NULL;
    first->w = rand()%1000;
    for(int i = 0; i < 1000000; i++){
        add(first, rand()%1000);
    }
    auto start = chrono::high_resolution_clock::now();
    first = merge_sort(first);
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    cout<<"Elapsed time: "<<elapsed.count() << endl;
}