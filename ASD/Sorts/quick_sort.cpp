#include <bits/stdc++.h>

using namespace std;

void swap(int&, int&);
int partition(int*, int, int);
void quick_sort(int*, int, int);

int partition(int* tab, int p, int k){
    int x = tab[p]; //choosing the pivot to partition the tabele
    int i = p - 1; //initializing beginign indexes
    int j = k + 1;
    while(true){ //main loop of partition
        do
        {
            i++;
        } while (tab[i] < x);
        do
        {
            j--;
        } while (tab[j] > x);
        if(i < j){
            swap(tab[i], tab[j]);
        }else return j;

    }
}

void quick_sort(int *tab, int p, int k){
    if(p < k){
        int r = partition(tab, p, k);
        quick_sort(tab, p, r);
        quick_sort(tab, r+1, k);
    }

}

void swap(int &a, int &b){
    int swap = a;
    a = b;
    b = swap;
}
int main(){
    int test[] = {rand()%100,rand()%100,rand()%100,rand()%100,rand()%100,rand()%100,rand()%100,rand()%100,rand()%100,rand()%100,rand()%100};
    for(int a : test)cout<<a<<" ";
    cout<<endl;
    quick_sort(test, 0, 10);
    for(int a : test)cout<<a<<" ";
    cout<<endl; 
}