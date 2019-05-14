#include <bits/stdc++.h>
 
using namespace std;

#define left(i)  2*i
#define right(i)  2*i+1
#define parent(i)  i/2

struct node{
    int pos = 0;
    int size;
    int *array;

    node(int s, int* a ){
        size = s;
        array = a;
        pos = size-1;
    }

    int pop(){
        return array[pos--];
    }
    int top(){
        return array[pos];
    }
};

struct heap{
    int size = 0;
    node *heap[20];

    void insert(node* element){
        size++;
        int i = size;
        while(i > 1 && element->top() > heap[parent(i)]->top()){
            heap[i] = heap[parent(i)];
            i = parent(i);
        }
        heap[i] = element;
    }

    int get_max(){
        int t = heap[1]->pop();
        if(heap[1]->pos == -1 && size >= 1){
            delete heap[1]; heap[1]=nullptr;
            heap[1] = heap[size];
            size--;
        }
        if(size > 0)heapify(1);
        return t;
    }

    void heapify(int n){
        int val = heap[n]->top();
        int largest = n;

        if(right(n) <= size && heap[right(n)]->top() > val){
            largest = right(n);
        }
        if(left(n) <= size &&  heap[left(n)]->top() > heap[largest]->top()){
            largest = left(n);
        }
        if(largest != n){
            node* s = heap[largest];
            heap[largest] = heap[n];
            heap[n] = s;
            heapify(largest);
        }
    } 
};


int main(){
    node* a1 = new node(6, new int[6]{1,7,9,9,12,15});
    node* a2 = new node(3, new int[3]{1,4,6});//
    node* a3 = new node(4, new int[4]{4,6,8,8});//
    node* a4 = new node(2, new int[2]{5,7});//
    node* a5 = new node(3, new int[3]{3,4,6});//

    heap* lol = new heap;
    lol->insert(a1);
    lol->insert(a2);
    lol->insert(a3);
    lol->insert(a4);
    lol->insert(a5);
    
    // cout<<lol->heap[1]->top()<<endl;
    // cout<<lol->heap[2]->top()<<endl;
    // cout<<lol->heap[3]->top()<<endl;
    // cout<<lol->heap[4]->top()<<endl;
    // cout<<lol->heap[5]->top()<<endl;

    while(lol->size > 0)
    {
        cout<<lol->get_max()<<" "<<lol->size;
        getchar();
    }

    cout<<endl;

}
