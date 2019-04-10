#include <bits/stdc++.h>

using namespace std;

struct node
{
    int key;
    node *p;
    node *l;
    node *r;

    node(int key)
    {
        this->key = key;
        this->p = NULL;
        this->l = NULL;
        this->r = NULL;
    }
};

void insert(node *&, node *);
void remove(node *&, node*);
node *treeSuccessor(node *);
node *treeMin(node *);
node *treeMax(node *);

void insert(node *&tree, node *toInsert)
{
    node* y = NULL;
    node* x = tree;
    while(x != NULL){
        y = x;
        if(toInsert->key >= x->key){
            x = x->r;
        }else{
            x = x->l;
        }
    }
    toInsert->p = y;
    if(y == NULL){
        tree = toInsert;
    }else{
        if(toInsert->key >= y->key){
            y->r = toInsert;
        }else{
            y->l = toInsert;
        }
    }
}

void myRemove(node *&tree, node *z){
    node* y, *x;

    if(z->l == NULL or z->r == NULL){
        y = z;
    }else{
        y = treeSuccessor(z);
    }

    if(y->r != NULL){
        x = x->r;
    }else{
        x = y->l;
    }
    if(x != NULL) x->p = y->p;
    if(y->p == NULL){
        tree = x;
    }else if(y == y->p->l){
        y->p->l = x;
    }else{
        y->p->r = x;
    }

    if(y != z){
        z->key = y->key;
    }
}

void remove(node *&tree, node* z)
{
    node* y;
    node* x;
    if(z->l == NULL or z->r == NULL){
        y=z;
    }else{
        y = treeSuccessor(tree);
    }
    if(y->l != NULL){
        x = y->l;
    }else{
        x = y->r;
    }

    if(x != NULL){
        x->p = y->p;
    }
    if(y->p == NULL){
        tree = x;
    }else if(y == y->p->l){
        y->p->l = x;
    }else{
        y->p->r = x;
    }

    if(y != z){
        z->key = y->key;
    }
}

node* treeMin(node *tree)
{
    node *temp = NULL;
    while (tree != NULL)
    {
        temp = tree;
        tree = tree->l;
    }
    return temp;
}

node* treeMax(node *tree){
    node* temp = NULL;
    while(tree != NULL){
        temp = tree;
        tree = tree->r;
    }
    return temp;
}

node *treeSuccessor(node *x)
{   
    if (x->r != NULL)
    {
        return treeMin(x->r);
    }
    node* p = x->p;
    while(p != NULL && p->r == x){
        x = p;
        p = x->p;
    }
    return p;
}

void inorderTreeWalk(node *tree)
{
    if (tree != NULL)
    {
        inorderTreeWalk(tree->l);
        cout << tree->key << " ";
        inorderTreeWalk(tree->r);
    }
}

int main()
{
    node *tree = NULL;
    node *n1 = new node(8);
    node *n2 = new node(9);
    node *n3 = new node(6);

    insert(tree, new node(10));
    insert(tree, new node(5));
    insert(tree, new node(7));
    insert(tree, n1);
    insert(tree, n3);
    insert(tree, n2);
    cout << endl;
    inorderTreeWalk(tree);
    cout << endl;
    // cout<<"Succ of "<<n1->key<<" is "<<treeSuccessor(n1)->key<<endl;
    // cout<<"Succ of "<<n2->key<<" is "<<treeSuccessor(n2)->key<<endl;
    // cout<<"Succ of "<<n3->key<<" is "<<treeSuccessor(n3)->key<<endl;
    remove(tree, n1);
    inorderTreeWalk(tree);
    cout<<endl;
    remove(tree, n2);
    inorderTreeWalk(tree);
    cout<<endl;
    remove(tree, n3);
    inorderTreeWalk(tree);
    cout<<endl;
}