#include <bits/stdc++.h>

using namespace std;

const int MAX = 5;

void func2(int a){
    a = 1000;
}

int maxInTab(int tab[MAX]){
    int index = 0;
    for(int i = 1; i < MAX; i++){
        //index = (tab[index] < tab[i])?i:index;
        if(tab[index] < tab[i]){
            index = i;
        }
    }
    return index;
}

int minInTab(int tab[MAX]){
    int index = 0;
    for(int i = 1; i < MAX; i++){
        //index = (tab[index] < tab[i])?i:index;
        if(tab[index] > tab[i]){
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

    out[0] = minInTab(w);
    out[1] = maxInTab(k);
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