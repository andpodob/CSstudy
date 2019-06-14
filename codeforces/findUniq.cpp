#include <bits/stdc++.h>

using namespace std;

int xor3(int a, int b){
    int i = 0;
    int result = 0;
    while(a != 0 or b != 0){
        result+=( ( (a%3) + (b%3) ) % 3 )*pow(3,i++);
        a/=3;b/=3;
    }
    return result;
}

int findUniq(int *tab, int n){
    int result = 0;
    for(int i = 0; i < n; i++){
        result = xor3(result, tab[i]);
    }
    return result;
}

int main(){
    int n; cin>>n;
    int tab[n];
    for(int i= 0; i < n; i++){
        cin>>tab[i];
    }
    cout<<findUniq(tab, n)<<endl;
}