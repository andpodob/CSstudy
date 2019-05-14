#include <bits/stdc++.h>

using namespace std;

struct node{
    double w;
    node* next;

    node(double init){
        next = NULL;
        w = init;
    }
};

struct myList{
    node* head;
    node* tail;
    int size;
    void addElement(node* element){
        element->next = NULL;
        if(head == NULL){
            head = element;
            tail = element;
        }else{
            tail->next = element;
            tail = tail->next;
        }
        size++;
    }
    node* cut_first(){
        if(size != 0){
            size--;
            node* temp = head;
            if(head == tail){
                head = NULL;
                tail = NULL;
            }else{
                head = head->next;
            }
            return temp;
        }else return NULL;
    }
};

myList concat_lists(myList list1, myList list2){
    if(list1.size == 0) return list2;
    if(list2.size == 0) return list1;
    list1.tail->next = list2.head;
    list1.tail = list2.tail;
    list1.size+=list2.size;
    return list1;
}

myList quicker_sort(myList list){
    if(list.size == 0)return list;
    double pivot = list.head->w;
    myList list1, list2, list3;
    list3.head = list3.tail = list2.head = list2.tail = list1.tail = list1.head = NULL;
    list1.size = list2.size = list3.size = 0;

    while(list.size > 0){
        if(list.head->w > pivot){
            list3.addElement(list.cut_first());
        }else if(list.head->w < pivot){
            list1.addElement(list.cut_first());
        }else{
            list2.addElement(list.cut_first());
        }
    }    

    list1 = quicker_sort(list1);
    list3 = quicker_sort(list3);

    list1 = concat_lists(list1, list2);
    list1 = concat_lists(list1, list3);

    return list1;   
}

myList bucketSort(myList list, int n){
    myList buckets[n], toReturn;
    for(int i = 0; i<n; i++){
        buckets[i].head=nullptr;
        buckets[i].tail=nullptr;
        buckets[i].size=0;
    }
    while(list.size > 0){
        buckets[(int)(n*list.head->w)].addElement(list.cut_first());   
    }
    toReturn = quicker_sort(buckets[0]);
    for(int i = 1; i<n; i++){
        buckets[i] = quicker_sort(buckets[i]);
        toReturn = concat_lists(toReturn, buckets[i]);
    }
    return toReturn;
}



void print(myList l){
    if(l.size == 0) return;
    node* temp = l.head;
    do{
        cout<<temp->w<<" ";
        temp = temp->next;
    }while(temp != nullptr);
    cout<<endl;
}

int main(){
    myList test;
    test.head = test.tail = NULL;
    test.size = 0;
    for(int i = 0; i<1000; i++){
        test.addElement(new node((rand()%100)/100.0));
    }
    print(test);
    test = bucketSort(test, 1000);
    print(test);
}