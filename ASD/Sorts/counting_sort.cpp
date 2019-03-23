#include <bits/stdc++.h>

using namespace std;

void CountingSort(int A[], int B[], int k, int n){
    int i;
    int C[k];
    for(i = 0; i < k; i++)C[i] = 0;
    for(i = 0; i < n; i++)C[A[i]]++;
    for(i = 1; i < k; i++)C[i] += C[i-1];
    for(i = 0; i < n; i++)B[--C[A[i]]] = A[i];
}

int main(){
    int A[10] = {rand()%100,rand()%100,5,rand()%100,rand()%100,5,rand()%100,rand()%100,5,rand()%100};
    int B[10] = {};
    for(int a : A) cout<<a<<" ";
    cout<<endl;
    cout<<"Counting sort: "<<endl;
    CountingSort(A,B,100,10);
    for(int a : B) cout<<a<<" ";
    cout<<endl;
}