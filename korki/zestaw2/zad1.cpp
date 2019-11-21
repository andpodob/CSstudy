#include <bits/stdc++.h>

using namespace std;

bool func(int N){
    int tab[N];
    tab[0] = 1;
    tab[1] = 1;
    int i = 2;
    for(; tab[i-1] < N; i++){
        tab[i] = tab[i-1]+tab[i-2];
    }
    for(int m = 0; m < i; m++){
        for(int n = m; n < i; n++){
            if(tab[m]*tab[n] == N) return true;
        }
    }
    return false;
}

int len(int n){
    return log10(n)+1;
}

int main(){
    log10()+1;
}