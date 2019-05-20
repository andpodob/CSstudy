#include <bits/stdc++.h>

using namespace std;


struct ReleasingQue{
    int* que;
    int iterator;
    ReleasingQue(int N){
        iterator = 0;
        que = new int[N];
        for(int i = 0; i<N; i++){
            que[i] = -1;
        }
    }
    void pushBack(int a){
        que[iterator++] = a;
    }
};

struct HuntingList{
    HuntingList* next;
    int predator;
    int prey;
};

struct List{
    int pokemon;
    List* next;
};

struct Pokemon{
    bool released;
    int huntersSize;
    int praySize;
    List* my_pray; //listy z wartownikiem
    List* hunters;
    Pokemon(){
        released = false;
        my_pray = NULL;
        hunters = NULL;
    }
    void add_Prey(int a){
        if(my_pray == NULL){
            praySize = 1;
            my_pray = new List;
            my_pray->next = NULL;
            my_pray->pokemon = a;
        }else{
            praySize++;
            List *p = new List();
            p->pokemon = a;
            p->next = my_pray;
            my_pray = p;
        }
    }
    void add_Hunters(int a){
        if(hunters == NULL){
            huntersSize = 1;
            hunters = new List;
            hunters->next = NULL;
            hunters->pokemon = a;
        }else{
            huntersSize++;
            List *p = new List();
            p->pokemon = a;
            p->next = hunters;
            hunters = p;
        }
    }
};

void recuReleasing(Pokemon** p, ReleasingQue *q, int i){
    int c = 0;
    List *temp = p[i]->my_pray;
    while (temp!= NULL && c < 2)
    {
        if(p[temp->pokemon]->released == true){
            c++;
        }
        temp = temp->next;
    }
    if(c == 2){
        temp = p[i]->hunters;
        p[i]->released = true;
        q->pushBack(i);
        while(temp != NULL){
            if(p[temp->pokemon]->released == false)recuReleasing(p, q, temp->pokemon);
            temp = temp->next;
        }
    }
}

int* releaseThemAll(HuntingList* list, int n){
    ReleasingQue *q = new ReleasingQue(n);
    Pokemon* pokemnons[n];
    for(int i = 0; i < n; i++){
        pokemnons[i] = new Pokemon();
    }
    while(list != NULL){
        pokemnons[list->predator]->add_Prey(list->prey);
        pokemnons[list->prey]->add_Hunters(list->predator);
    }
    //wypuszczamy spokojne pokemnony
    for(int i = 0; i < n; i++){
        if(pokemnons[i]->praySize == 0){
            q->pushBack(i);
            pokemnons[i]->released = true;
        }
    }

    //wypuszczamy drapiezne pokemony
    for(int i = 0; i < n; i++){
        if(pokemnons[i]->released == false){
            recuReleasing(pokemnons, q, i);
        }
    }

    return q->que;
}

int main(){

}