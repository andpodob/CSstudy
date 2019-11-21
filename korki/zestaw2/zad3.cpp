#include <bits/stdc++.h>

using namespace std;

int len10(int n){
    return log10(n)+1;
}

int len2(int n){
    return log2(n)+1;
}

int first(int n, int p){
    return n/p;
}

int last10(int n){
    return n%10;
}

int last2(int n){
    return n%2;
}

bool isPalindrome10(int n){
    int l =  len10(n);
    int p = pow(10, l-1);
    while (n > 0)
    {
        if(first(n, p) != last10(n)){
            return false;
        }
        n = n%p;
        n = n/10;
        p = p/100;
    }
    return true;
}

bool isPalindrome2(int n){
    int l =  len2(n);
    int p = pow(2, l-1);
    while (n > 0)
    {
        if(first(n, p) != last2(n)){
            return false;
        }
        n = n%p;
        n = n/2;
        p = p/4;
    }
    return true;
}

int main(){
    int n = 414;
    cout<<isPalindrome10(n)<<endl;
    n = 4564;
    cout<<isPalindrome10(n)<<endl;
}