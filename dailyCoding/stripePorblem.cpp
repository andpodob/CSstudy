/*
    This problem was asked by Stripe.

    Given an array of integers, find the first missing positive integer in linear time and constant space. In other words,
    find the lowest positive integer that does not exist in the array.The array can contain duplicates and negative numbers
    as well.

    For example, the input [3, 4, -1, 1] should give 2. The input [1,2,0] should give 3.

    You can modify the input array in-place.
 */

#include <bits/stdc++.h>

using namespace std;

void swap(int &a, int &b){
    a=a^b;
    b=a^b;
    a=a^b;
}

int func(int A[], int n){
    int i = 1;
    while(i <= n){
        if(A[i-1] >= n or A[i-1] <= 0) i++;
        else{
            swap(A[i-1], A[A[i-1]-1]);
            if(A[i-1] == i) i++;
        }
    }

    for(int i = 0; i < n; i++){
        if(A[i] != i+1) return i+1;
    }

    return -1;
}

int main(){
    int n = 11;
    int A[n] = {-2, -1, 1, 6, 0, 4, 3, 2, 38, 198, -4567};
    cout<<func(A, n)<<endl;
}