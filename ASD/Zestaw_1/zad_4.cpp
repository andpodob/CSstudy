#include <bits/stdc++.h>

using namespace std;

// void swap(int &a, int &b){

// }

void merge(int* tab, int p, int sr, int k){
    
    

    int pocz = p; int kon = k;
    int N = k-p+1;
    int pomoc[k-p+1];
    int m = sr+1;
    int i = 0;
    
    while(p < sr && m <= k){
        if(tab[p] < tab[m]){
            pomoc[i]=tab[p];
            p++;
        }else{
            pomoc[i] = tab[m];
            m++;
        }
        i++;
    }
    while(p < sr){
        pomoc[i] = tab[p];
        p++;
        i++;
    }
    while(m <= k){
        pomoc[i] = tab[m];
        m++;
        i++;
    }

    for(int i = pocz; i<=kon; i++)tab[i] = pomoc[i-pocz];
}

void merge_sort(int *tab, int p, int k){
if(p-k==0)return;
    
    
    if(p < k){
       // for (int i =0;i<k;i++) cout<<tab[i]<<" ";
        int m = (p+k)/2;
        merge_sort(tab, p, m);
        merge_sort(tab, m+1, k);
        merge(tab, p,m,k);
    }
}

int main(){
    int tab[10] = {rand()%100,rand()%100,rand()%100,rand()%100,rand()%100,rand()%100,rand()%100,rand()%100,rand()%100,rand()%100};
    for (int a : tab) cout<<a<<" ";
    cout<<endl;
    merge_sort(tab, 0, 9);
    for (int a : tab) cout<<a<<" ";
    cout<<endl; 

//     int tab[1] = {1};

//     merge(tab, 0,0,0);

//    for(int a : tab)cout<<a<<" ";

   


}