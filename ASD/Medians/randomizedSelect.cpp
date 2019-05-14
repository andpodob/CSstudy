#include <bits/stdc++.h>

using namespace std;

void swap(int &a, int &b){
    b = a ^ b;
    a = a ^ b;
    b = a ^ b;
}

int partition(int *tab, int p, int k){
    int i = p-1;
    int j = k+1;
    int pivot = tab[p];
    while(true){
        do{
            i++;
        }while(tab[i] < pivot);
        do{
            j--;
        }while(tab[j] > pivot);
        if(i < j){
            swap(tab[i], tab[j]);
        }else return j;
    }
}

int randomized_select(int *tab, int p, int k, int r){
    int q, len;
    if(p == k) return tab[k];
    
    q = partition(tab, p, k);
    len = q-p+1;

    if(len <= r) return randomized_select(tab, q+1, k, r-len);
    else return randomized_select(tab, p, q, r);
}


int main(){
    int N = 250000;
    int tab[N];
    for(int i = 0; i<N; i++){
        tab[i] =  i;
    }
    auto start = chrono::high_resolution_clock::now();
    int element = randomized_select(tab, 0, N-1,(N*3)/4);
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    cout<<"Elapsed time: "<<elapsed.count() << endl;
    cout<<"Element on: "<<(N*3)/4<<" position is: "<<element<<endl;
}