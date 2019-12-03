#include <bits/stdc++.h>

using namespace std;

void f(int a){
    if(a == 0)return;
    f(a-1);
    cout<<a<<" "; 
}

int fib(int n){
    return fib(n-1)+fib(n-2);
    if(n == 1) return 1;
    if(n == 2) return 1;
    //return fib(n-1)+fib(n-2);
}

bool odwaz(int M, int i, int odwazniki[], int len){
    if(M-odwazniki[i-1] == 0) return true;
    if(i == len) return false;
    
    return (odwaz(M, i+1,odwazniki, len) or odwaz(M-odwazniki[i], i+1, odwazniki, len));
} 

bool isPrime(int n){
    if(n == 1 || n == 0) return false;
    if(n == 2) return true;
    if(n%2 == 0) return false;
    for(int i = 3; i <= sqrt(n); i+=2){
        if(n%i == 0) return false;
    }
    return true;
}

bool cutPrimes(){
    
}

bool odwazV2(int M, int i, int odwazniki[], int len){
    if(M-odwazniki[i-1] == 0) return true;
    if(M+odwazniki[i-1] == 0) return true;
    if(i == len) return false;
    
    return (odwaz(M, i+1,odwazniki, len) or odwaz(M-odwazniki[i], i+1, odwazniki, len) or odwaz(M+odwazniki[i], i+1, odwazniki, len));
}


bool isPorperPalindrome(int tab[], int begin, int end){
    while(begin < end){
        if(tab[begin] != tab[end] or tab[begin]%2==0 or tab[end]%2 == 0) return false;
        begin++;
        end--;
    }
    if(tab[begin]%2 == 0)return false;
    return true;
}

int max(int a, int b){
    return (a > b)? a : b;
}

int longestProperPalindrome(int tab[], int n){
    int MAX = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j <n; j++){
            if(isPorperPalindrome(tab, i, j)){
                MAX = max(MAX, 1+(j-i)/2);
            }
        }
    }
    return MAX;
}

int main(){
    //longestProperPalindrome({}, 5);
    // f(5);
    // fib(5);

    // int odwazniki[] = {3,3,3,8,5};
    // int odwazniki2[] = {3,3,3,4,5};

    // cout<<odwaz(15, 0, odwazniki2, 5)<<endl;
    for(int i=0; i <= 17; i++){
        cout<<i<<" "<<isPrime(i)<<endl;
    }
}