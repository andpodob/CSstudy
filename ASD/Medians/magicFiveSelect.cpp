#include <bits/stdc++.h>
#include <cmath>


using namespace std;

void swap(int &a, int &b){
    b = a ^ b;
    a = a ^ b;
    b = a ^ b;
}

int partition(int *tab, int p, int k, int pivot){
    int i = p-1;
    int j = k+1;
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

void insertion_sort(int *tab, int p, int k){
    int temp = 0, j = 0;
    for(int i = p+1; i <= k; i++){
        temp = tab[i];
        j = i-1;
        while(j >= p && temp < tab[j]){
            tab[j+1]=tab[j];
            j--;
        }
        tab[j+1] = temp;
    }
}

int medianOfMedians(int *tab, int p, int k){
    int n = k-p+1;
    n=(n%5 == 0)?n/5:n/5+1;
    int medians[n];
    int i = p;
    int j = 0;
    if(n == 1) return tab[(p+k)/2];
    while(i+4 <= k){
        insertion_sort(tab, i, i+4);
        medians[j++]=tab[i+2];
        i+=5;
    }
    insertion_sort(tab, i, k);
    if(j < n)medians[j] = tab[(i+k)/2];
    return medianOfMedians(medians,0,n-1);
}

int select(int *tab, int p, int k, int r){
    int q, len, pivot;
    if(p == k) return tab[k];
    else{
        pivot = medianOfMedians(tab, p, k);
        q = partition(tab, p, k, pivot);
        len = q-p+1;
        if(len <= r)return select(tab, q+1, k, r-len);
        else return select(tab, p, q, r);
    }
}


int main(){
    int N = 250000;
    int tab[N];
    for(int i = 0; i<N; i++){
        tab[i] =  i;
    }
    auto start = chrono::high_resolution_clock::now();
    int element = select(tab, 0, N-1,(N*3)/4);
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    cout<<"Elapsed time: "<<elapsed.count() << endl;
    cout<<"Element on: "<<(N*3)/4<<" position is: "<<element<<endl;
}