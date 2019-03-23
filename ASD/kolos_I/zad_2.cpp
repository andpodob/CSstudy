#include <bits/stdc++.h>

using namespace std;

void swap(int &a, int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void insertion_sort(int T[], int p, int k){
    int j = 0, temp;
    for(int i = p+1; i <= k; i++){
        j = i - 1;
        temp = T[i];
        while(j >= p && T[j] > temp){
            T[j+1] = T[j];
            j--;
        }
        T[j+1] = temp;
    }
}

int medianOfMedians(int T[], int p, int k){
    int N = (k-p+5)/5;
    int j = 0, i=0;
    if(N <= 10){
        return T[(p+k)/2];
    }else{
        int medians[N];
        for(i = p; i <= k-4; i+=5){
            insertion_sort(T, i, i+4);
            medians[j++] = T[i+2];
        }
        insertion_sort(T, i, k);
        medians[j] = T[(i+k)/2];
        return medianOfMedians(medians, 0, N-1);
    }
}

int partition(int T[], int p, int k, int pivot){
    int i = p-1;
    int j = k+1;
    while(true){
        do{
            i++;
        }while(T[i] < pivot);
        do{
            j--;
        }while(T[j] > pivot);
        if(j > i){
            swap(T[i], T[j]);
        }else{
            return j;
        }
    }
}

int n_th_el(int *tab, int p, int k, int r){
    int q, lengthLeftPart, pivot;
    if(p < k){
        pivot = medianOfMedians(tab, p, k);
        q = partition(tab, p, k, pivot);
        lengthLeftPart = q-p;
        if(lengthLeftPart == r) return tab[q];
        else if (lengthLeftPart < r)
        {
            return n_th_el(tab, q+1, k, r-lengthLeftPart-1);
        }else
        {
            return n_th_el(tab, p, q-1, r);
        }
    }else return tab[k];
}

int SumBetween(int T[], int from, int to, int n){
    int sum = 0;
    for(int i = from; i <= to; i++){
        sum+=n_th_el(T, 0, n-1, i);
    }
    return sum;
}

int main(){
    int T[100];
    for(int i = 0; i < 100; i++){
        T[i] = rand()%100;
    }

    for(int i = 0; i < 100; i++)cout<<T[i]<<" ";
    cout<<endl;
    // insertion_sort(T, 0, 9);
    // for(int i = 0; i < 10; i++)cout<<T[i]<<" ";
    cout<<SumBetween(T, 23, 78, 100);
    cout<<endl;
}