#include <bits/stdc++.h>

using namespace std;

void lomouto_partition(int *A, int low, int high){
    int pivot = A[high];
    int i = low - 1;
    for(int j = low; j <= high-1; j++){
        if(A[j] <= pivot){
            i++;
            swap(A[j], A[i]);
        }
    }
}

int main(){

}