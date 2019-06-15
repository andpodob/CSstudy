/*
    This problem was asked by Google.

    Given an array of integers where every integer occurs three times
    except for one integer, which only occurs once, find and return the
    non-dupclicated integer.

    For example, given [6, 1, 3, 3, 3, 6, 6,], return 1. Given [13, 19, 13, 13],
    return 19.

    Do this in O(n) time and O(1) space.
 */

#include <bits/stdc++.h>

using namespace std;

int xor3(int a, int b){
    int i = 0;
    int result = 0;
    while(a != 0 or b != 0){
        result+=( ( (a%3) + (b%3) ) % 3 )*pow(3,i++);
        a/=3;b/=3;
    }
    return result;
}

int findUniq(int *tab, int n){
    int result = 0;
    for(int i = 0; i < n; i++){
        result = xor3(result, tab[i]);
    }
    return result;
}

int main(){
    int n; cin>>n;
    int tab[n];
    for(int i= 0; i < n; i++){
        cin>>tab[i];
    }
    cout<<findUniq(tab, n)<<endl;
}