// C program to implement Bubble Sort on singly linked list 
#include<bits/stdc++.h> 

using namespace std;

void merge(int *tab, int pocz, int sr, int kon){
    int n = kon-pocz+1;
    int s = sr+1, p = pocz;
    int pomoc[n];
    for(int i = 0; i < n; i++){
        if(s == kon+1){
            pomoc[i] = tab[p];
            p++;
        }else if(p == sr+1){
            pomoc[i] = tab[s];
            s++;
        }else if(tab[p] < tab[s]){
            pomoc[i] = tab[p];
            p++;
        }else{
            pomoc[i] = tab[s];
            s++;
        }
    }
    for(int i = pocz; i<=kon; i++)tab[i] = pomoc[i-pocz];
}

void merge_sort(int *tab, int pocz, int kon){
    int sr;
    if(pocz < kon){
        sr = (pocz+kon)/2;
        merge_sort(tab, pocz, sr);
        merge_sort(tab, sr+1, kon);
        merge(tab, pocz, sr, kon);
    }
}

int main(){
    int tab[] = {1,8,5,53,38,43,27,3,2,1,1,1,1,1};
    for(int a : tab) cout<<a<<" ";
    cout<<endl;
    merge_sort(tab, 0, 13);
    for(int a : tab) cout<<a<<" ";
    cout<<endl;
}