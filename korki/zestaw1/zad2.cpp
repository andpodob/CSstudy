#include <bits/stdc++.h>

using namespace std;

const int rok = 2019;

bool fib(int a, int b){
    cout<<a<<" ";
    cout<<b<<" ";
    int c = a + b;
    cout<<c<<" ";
    while(c < rok){
        a = b;
        b = c;
        c = a + b;
        cout<<c<<" ";
    }
    cout<<endl;
    return (c == rok);
}

void findStartingPoints(){
    bool find = false;
    int n = 2;
    int a, b;
    while(!find){
        a = 1; b = n-1;
        while(a <= b && !find){
            cout<<a<<" "<<b<<endl;
            find = fib(a, b);
            a+=1;
            b-=1; 
        }
        n++;
    }
}

void pairs(int n){
    int a = 1, b = n-1;
    while(a <= b){
        cout<<a<<" "<<b<<endl;
        a+=1;
        b-=1; 
    }
}

int main(){
    fib(6,33);
    //pairs(6);
    //findStartingPoints();
}