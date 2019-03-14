#include <bits/stdc++.h>

using namespace std;

int merge(int*, int, int, int);
int merge_sort(int*, int, int);

int merge(int* tab, int p, int sr, int k){
    int N = k-p+1;
    int t[N]; //auxiliar array
    xd xd
    int i = p; //left half iterator
    int j = sr;//right half iterator
    int aux = 0; //iterator of auxiliar array

    int inv_count = 0;

    while((i <= (sr-1)) && (j <= k)){
        if(tab[i] <= tab[j]){ 
            t[aux++] = tab[i++];
        }else{
            inv_count += (sr-i);
            t[aux++] = tab[j++];
        }
    }
    while(i <= (sr - 1)){
        t[aux++] = tab[i++];
    }
    while(j <= k){
        t[aux++] = tab[j++];
    }
    
    for(int i = 0 ; i < N; i++) tab[p+i] = t[i];

    return inv_count;
}

int merge_sort(int *tab, int p, int k){
    int sr = (p+k)/2 + 1;
    int inv_count = 0;
    if(p < k){
        inv_count = merge_sort(tab, p, sr-1);
        inv_count += merge_sort(tab, sr, k);
        inv_count += merge(tab, p, sr, k);
    }
    return inv_count;
}

int main(){
    int a[10] = {rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10};
    for(int b : a)cout<<b<<" ";
    cout<<endl;
    cout<<merge_sort(a, 0, 9)<<endl;
    for(int b : a)cout<<b<<" ";
    cout<<endl;
}