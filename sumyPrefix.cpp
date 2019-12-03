#include <bits/stdc++.h>

using namespace std;

int next(int a, int b){
    return a+b;
}

bool fibSum(int s){
    int a1=1, b1=1;
    int a2=1, b2=1;

    int sum = 0;
    
    while(a1 < 1000){
        if(sum){

        }
    }
}

bool checkArray(int tab[], int S, int len){
    int prefixSums[len+1];
    int sum = 0;
    
    prefixSums[0] = 0;
    for(int i = 0; i < len; i++){
        sum+=tab[i];
        prefixSums[i+1] = sum;
    }

    int p = 0, q = 1;
    while (q < len+1)
    {   
        if(prefixSums[q] - prefixSums[p] == S) return true;
        if(prefixSums[q] - prefixSums[p] > S){
            p++;
        }
        if(prefixSums[q] - prefixSums[p] < S){
            q++;
        }
    }
    return false;
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

bool cutPrimes(int tab[], int idx, int len){
    
    int num = 0;
    if(idx == len) return true;
    for(int i = idx; i < len; i++){
        num*=2;
        num+=tab[i];
        if(isPrime(num)){
            if(cutPrimes(tab,i+1, len)) return true;
        }
    }
    return false;
}

int main(){
    int tab[] = {1,0,0,1,0,0};
    cout<<cutPrimes(tab, 0, 6)<<endl;
}