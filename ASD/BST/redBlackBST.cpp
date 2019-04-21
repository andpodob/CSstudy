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

void leftRotation(node* &tree, node* x){
    node *y;
    if(x->r != NULL){
        y = x->r;
        if(x == tree){
            tree = y;
        }
        y->p = x->p;
        if(x->p != NULL and x->p->key > y->key){
            x->p->l = y;
        }else if(x->p != NULL){
            x->p->r = y;
        }
        x->p = y;
        x->r = y->l;
        y->l = x;
        if(x->r != NULL)x->r->p = x;
    }
}

void rigthRotation(node* &tree, node* x){
    node *y;
    if(x->l != NULL){
        y = x->l;
        if(x == tree)tree = y;
        y->p = x->p;
        if(x->p != NULL and x->p->key > y->key){
            x->p->l = y;
        }else if(x->p != NULL){
            x->p->r = y;
        }
        x->p = y;
        x->l = y->r;
        y->r = x;
        if(x->l != NULL)x->l->p = x;
    }
}

void rbInsert(node *&tree, node* x){
    treeInsert(tree, x);
    x->color = RED;

    node *y =NULL;
    while(x->p != NULL and x->p->color == RED){
        if(x->p->p != NULL){
            if(x->p == x->p->p->l){
                y = x->p->p->r; //y jest stryjem wstawianego wezla
                //1 PRZYPADEK (stryj jest tak samo jak ojciec czerwony)
                if(y != NULL and y->color == RED){
                    y->color = BLACK;
                    x->p->color = BLACK;
                    x->p->p->color = RED;
                    x = x->p->p;
                }
                //PRZYPADEK 2
                else{ 
                    if(x == x->p->r){ //jezeli stryj jest czarny oraz wstawiany jest prawym dzieckiem
                    leftRotation(tree, x->p);//robimy rotację w lewo względem rodzica wstawianego wezla doprowadzajc tym samym do przypadku 3
                    x = x->l;
                    }
                    //PRZYPADEK 3
                    //wykonujemy prawą rotację wzgledem rodzica wezla
                    x = x->p;
                    rigthRotation(tree, x->p);
                    x->color = BLACK;
                    x->l->color = RED;
                    x->r->color = RED;
                    x = x->l;
                }
            }else{//przypadki symetryczne do tych u góry
                y = x->p->p->l;

                if(y != NULL and y->color == RED){
                    y->color = BLACK;
                    x->p->color = BLACK;
                    x->p->p->color = RED;
                    x = x->p->p;
                }else{
                    if(x == x->p->l){
                        rigthRotation(tree, x->p);
                        x = x->r;
                    }

                    x = x->p;
                    leftRotation(tree, x->p);
                    x->color = BLACK;
                    x->l->color = RED;
                    x->r->color = RED;
                    x = x->r;
                }
            }
        }else break;
    }
    tree->color = BLACK;
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


    for(int i = 0; i < 40; i++){
        rbInsert(tree, new node(rand()%1000+1));
    }

    preOrderTreeWalk(tree);

}