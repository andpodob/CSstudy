// Proszę zaproponować/zaimplementować algorytm scalający k posortowanych tablic
// o łącznej długości n w jedną posortowaną tablicę w czasie O(n*log(k))
  
#include <bits/stdc++.h>
 
using namespace std;
 
int insertion_index = 0;
const int k = 3;
 
int sizes[k];
int* arrays[k];
 
void insertTab(int* tab, int size){
  arrays[insertion_index] = tab;
  sizes[insertion_index] = size;
  insertion_index++;
}
 
void merge(int* tab, int *tab1, int* tab2, int size1, int size2){
  int k=0, y=0, i=0;
  while(k < size1 && y < size2){
    if(tab1[k] < tab2[y]){
      tab[i] = tab1[k];
      k++;
    }else{
      tab[i] = tab2[y];
      y++;
    }
    i++;
  }
  while(k < size1){
    tab[i] = tab1[k];
    k++;
    i++;
  }
  while(y < size2){
    tab[i] = tab2[y];
    y++;
    i++;
  }
}
 
// void merge_tabeles(){
//   int i = 2;
 
//   while(i < k){
//     for(int j = 0; j < k; j+=i){
//       int size = sizes[j]+sizes[j+i/2];
//       int tab[size];
//       merge(tab, arrays[j], arrays[j+i/2], sizes[j], sizes[j+i/2]);
//       arrays[j] = tab;
//       sizes[j] = size;
//     }
//     i*=2;
//   }
// }

void merge_tables(){
    int len = k;
    int index = 0;
    int iterations = 1;
    while(len > 1){
        cout<<iterations++<<endl;
        for(int i = 0; i+1 < len; i+=2){
            int tab[sizes[i]+sizes[i+1]];
            merge(tab, arrays[i],arrays[i+1], sizes[i], sizes[i+1]);
            for(int a : tab) cout<< a << " ";
            cout<<endl; 
            arrays[i] = nullptr;
            arrays[i+1] = nullptr;
            arrays[index] = tab;
            sizes[index] = sizes[i] + sizes[i+1];
            index++;
        }
        if(len % 2 != 0){
            arrays[index] = arrays[len-1];
            sizes[index] = sizes[len-1];
            arrays[len-1] = nullptr;
            len = len/2 + 1;
        }else len = len/2;

        index = 0;
    }
}
 
int main() {
  // int k = 5;
 
  int a1[] = {1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 6, 6, 6, 7, 7, 8}; //17
  int a2[] = {2, 6, 7}; //3
  int a3[] = {1, 2, 3, 4, 4, 4, 5, 6, 7, 7}; //10
  int a4[] = {1, 4, 7, 8}; //4
  int a5[] = {0, 0, 1, 2, 2, 2, 2, 3, 4, 4, 4, 5, 5, 8, 9, 9}; //16
 
  insertTab(a1, sizeof(a1)/sizeof(int));
  insertTab(a2, sizeof(a2)/sizeof(int));
  insertTab(a3, sizeof(a3)/sizeof(int));
//   insertTab(a4, sizeof(a4)/sizeof(int));
//   insertTab(a5, sizeof(a5)/sizeof(int));
 
  merge_tables();
 
//   for(int i = 0; i < sizes[0]; i++){
//     cout<<arrays[0][i]<<" ";
//   }

  cout<<endl;
}