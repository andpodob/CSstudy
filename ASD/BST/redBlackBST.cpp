#include <bits/stdc++.h>

using namespace std;

enum COLOR{
    RED, BLACK, NONE
};

struct node
{
    int key;
    node *p;
    node *l;
    node *r;
    COLOR color;

    node(int key)
    {
        this->key = key;
        this->p = NULL;
        this->l = NULL;
        this->r = NULL;
        this->color = NONE;
    }
};

void leftRotate(node*&, node*);
void rigthRotate(node*&, node*);
void treeInsert(node*&, node*);
void rbInsert(node*&, node*);
void preOrderTreeWalk(node*);

void treeInsert(node* &tree, node* x){
    if(tree == NULL)tree = x;
    else{
        node* y, *t = tree;
        while(t != NULL){
            y = t;
            if(x->key > t->key)t=t->r;
            else t = t->l;
        }
        if(x->key > y->key)y->r = x;
        else y->l = x;
        x->p = y;
    }
}

void preOrderTreeWalk(node* tree){
    if(tree != NULL){
        switch(tree->color){
            case BLACK:
                printf("%c",'b');
                break;
            case RED:
                printf("%c",'r');
                break;
        }
        printf("%d ",tree->key);
        preOrderTreeWalk(tree->l);
        preOrderTreeWalk(tree->r);
    }
}


int main(){
    node* tree = NULL;

    treeInsert(tree, new node(7));
    treeInsert(tree, new node(4));
    treeInsert(tree, new node(3));
    treeInsert(tree, new node(2));
    treeInsert(tree, new node(6));

    treeInsert(tree, new node(18));
    treeInsert(tree, new node(11));
    treeInsert(tree, new node(9));
    treeInsert(tree, new node(14));
    treeInsert(tree, new node(12));
    treeInsert(tree, new node(17));

    treeInsert(tree, new node(19));
    treeInsert(tree, new node(22));
    treeInsert(tree, new node(20));

    preOrderTreeWalk(tree);
    cout<<endl;
}