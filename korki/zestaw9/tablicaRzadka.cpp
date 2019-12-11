#include <bits/stdc++.h>

using namespace std;

struct Node{
    int index;
    int value;
    Node* next;
};

void init(Node*& tab){
    tab = new Node;
    tab->index = -1;
    tab->next = NULL;
}

int value(Node *tab, int n){
    while (tab != NULL and tab->index != n)
    {
        tab = tab->next;
    }
    if(tab != NULL){
        return tab->value;
    }
    return -1;
}

void setElement(Node* tab, int n, int value){
    while (tab->next != NULL and tab->next->index < n)
    {
        tab = tab->next;
    }
    
    
    if(tab->next == NULL){     
        Node* nowyWezel = new Node;
        nowyWezel->index = n;
        nowyWezel->value = value;
        nowyWezel->next = NULL; 
        tab->next = nowyWezel;
    }
    else if(tab->next->index == n){
        tab->next->value = value;
    }
    else{
        Node* nowyWezel = new Node;
        nowyWezel->index = n;
        nowyWezel->value = value; 
        
        Node* temp  = tab->next;
        tab->next = nowyWezel;
        nowyWezel->next = temp;
    }
}

void printList(Node* begin){
    while(begin != NULL){
        cout<<begin->index<<" : "<<begin->value<<", ";
        begin = begin->next;
    }
    cout<<endl;
}

int main(){
    Node* tab;
    init(tab);

    setElement(tab, 0, 15);
    setElement(tab, 1000000, 16);

    printList(tab);

    setElement(tab, 1000000, 25);

    printList(tab);

    setElement(tab, 1000, 13);

    printList(tab);

    cout<<"1000 : "<<value(tab, 1000)<<endl;
}