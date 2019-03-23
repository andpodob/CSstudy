#include <bits/stdc++.h>

using namespace std;


void swap(int &a, int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int partition(int T[], int p, int k){
    int i = p - 1;
    int j = k + 1;
    int pivot = T[p];
    while(true){
        do{
            i++;
        }while(T[i] < pivot);
        do{
            j--;
        }while(T[j] > pivot);
        if(i < j){
            swap(T[i], T[j]);
        }else return j;
    }
}

int select(int T[], int p, int k, int elInd){
    if(p == k) return T[k];
    int j, lengthLeftPart;
    j = partition(T, p, k);
    lengthLeftPart = j - p;
    if(p < k){
        if(lengthLeftPart == elInd)return T[j];
        else if(lengthLeftPart < elInd)return select(T, j+1, k, elInd-lengthLeftPart-1);
        else return select(T, p, j, elInd);
    }else return T[j];
}

int main(){
    int T[15];
    for(int i = 0; i < 15; i++){
        T[i] = rand()%100;
    }
    for(int a : T)cout<<a<<" ";
    cout<<endl;
    for(int i = 0; i < 15; i++)
        cout<<select(T, 0, 14, i)<<" ";

    cout<<endl;
}