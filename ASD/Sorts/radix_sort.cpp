#include <bits/stdc++.h>

using namespace std;


int char_to_digit(char a){
    return (int)a-48;
} 

void sortByPoss(string tab[], int poss, int n){
    int counters[10];
    string result[n];
    for(int i = 0; i<10; i++)counters[i] = 0;
    for(int i = 0; i < n; i++)counters[char_to_digit(tab[i][poss])]++;
    for(int i = 1; i < 10; i++)counters[i]+=counters[i-1];
    for(int i = n-1; i >= 0; i--) result[--counters[char_to_digit(tab[i][poss])]] = tab[i];
    for(int i = 0; i < n; i++)tab[i] = result[i];
}

void radix_sort(string tab[], int length, int n){
    for(int i = length-1; i >= 0; i--)sortByPoss(tab, i, n);
}


int main(){
    string tab[10] = {"123","213","321","354","582","104","321","918","932","621"};
    for(string a : tab) cout << a <<" ";
    cout<<endl;
    radix_sort(tab, 3, 10);
    for(string a : tab) cout << a <<" ";
}