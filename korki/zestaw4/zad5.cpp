#include <bits/stdc++.h>

using namespace std;

const int MAX = 5;

void func2(int a){
    a = 1000;
}

int maxInTabPos(int tab[MAX]){
    int index = 0;
    while (tab[index] < 0)
    {
        index++;
    }
    
    for(int i = index; i < MAX; i++){
        //index = (tab[index] < tab[i])?i:index;
        if(tab[i] > 0 && tab[index] < tab[i]){
            index = i;
        }
    }
    return index;
}

int minInTabPos(int tab[MAX]){
    int index = 0;
    while (tab[index] < 0)
    {
        index++;
    }
    for(int i = index; i < MAX; i++){
        //index = (tab[index] < tab[i])?i:index;
        if(tab[i] > 0 && tab[index] > tab[i]){
            index = i;
        }
    }
    return index;
}

int maxInTabNeg(int tab[MAX]){
    int index = 0;
    while (tab[index] > 0)
    {
        index++;
    }
    for(int i = 1; i < MAX; i++){
        //index = (tab[index] < tab[i])?i:index;
        if(tab[i] < 0 && tab[index] < tab[i]){
            index = i;
        }
    }
    return index;
}

int minInTabNeg(int tab[MAX]){
    int index = 0;
    while (tab[index] > 0)
    {
        index++;
    }
    for(int i = 1; i < MAX; i++){
        //index = (tab[index] < tab[i])?i:index;
        if(tab[i] < 0 && tab[index] > tab[i]){
            index = i;
        }
    }
    return index;
}

void func(int t[MAX][MAX], int out[2]){
    int k[MAX];
    int w[MAX];

    for(int i = 0; i < MAX; i++){
        k[i] = 0;
        w[i] = 0;
    }

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            w[i] += t[i][j];
        }
    }

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            k[i] += t[j][i];
        }
    }
    int neg[2];
    int pos[2];

    
    pos[0] = minInTabPos(w);
    pos[1] = maxInTabPos(k);

    neg[0] = maxInTabNeg(w);
    neg[1] = minInTabNeg(k);

    if(neg[1]/neg[0] > pos[1]/pos[0]){
        out[0]=neg[0];
        out[1]=neg[1];
    }else{
        out[0]=pos[0];
        out[1]=pos[1];
    }
}



int main(){
    int tab[2];
    cout<<tab<<endl;
    cout<<tab[0]<<" : "<<tab[1]<<endl;
    //func(tab, );
    //cout<<tab[0]<<" : "<<tab[1]<<endl;

    int a = 10;
    cout<<a<<endl;
    func2(a);
    cout<<a<<endl;
}