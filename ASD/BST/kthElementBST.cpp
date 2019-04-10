#include <bits/stdc++.h>

using namespace std;

struct node{
    node* p;
    node* r;
    node* l;
    int key;
    int sizeLeftTree;

    node(int key){
        sizeLeftTree = 0;
        this->key = key;
        this->r = NULL;
        this->l = NULL;
        this->p = NULL;
    }
};

void inorderTreeWalk(node *tree){
    if(tree != NULL){
        inorderTreeWalk(tree->l);
        tree->sizeLeftTree++;
        inorderTreeWalk(tree->r);
    }
}

void updateTree(node *tree){
    inorderTreeWalk(tree);
}

void insert(node *&tree, node* toInsert){
    node *x=tree, *y=NULL;
    while(x != NULL){
        y = x;
        if(toInsert->key >= x->key){
            toInsert->sizeLeftTree = x->sizeLeftTree+1;
            x=x->r;
        }
        else {
            x->sizeLeftTree++;
            updateTree(x->r);
            x = x->l;
        }
    }
    toInsert->p = y;
    if(y == NULL)tree = toInsert;
    else{
        if(toInsert->key >= y->key) y->r = toInsert;
        else y->l = toInsert;
    }
}


int kthElement(int tab[], int n, int k){
    node* tree = NULL;
    node* T[n];

    for(int i = 0; i < n; i++){
        T[i] = new node(tab[i]);
        insert(tree, T[i]);
    }

    for(int i = 0; i < n; i++){
        if(T[i]->sizeLeftTree == k) return T[i]->key;
    }
    return -1;
}

int main(){
    int tab[7] = {5,7,6,8,1,2,3};

    cout<<kthElement(tab, 7, 5)<<endl;
}