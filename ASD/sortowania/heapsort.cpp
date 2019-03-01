#include <bits/stdc++.h>

#define PARENT(i) i/2
#define RIGHT(i) 2*i+1
#define LEFT(i) 2*i

using namespace std;

/*
 In the folowing implementation od the heapsort i assumed convention with the size of heap at the 0-index,
 for example if heap has 3 elements, array will look like this:
    {3, el_1, el_2, el_3}
*/
void heapify(int*,int);
void build_heap(int*);

void build_heap(int *tab){
    for(int i = tab[0]; i >= 1; i--){
        heapify(tab, i);
    }
}

void heapify(int* tab, int i){
    int largest,swap;
    int l = LEFT(i);
    int r = RIGHT(i);

    if(l <= tab[0] && tab[l] > tab[i]){
        largest = l;
    }
    else{
        largest = i;
    }
    if(r <= tab[0] && tab[r] > tab[largest]){
        largest = r;
    }
    if(largest != i){
        swap = tab[largest];
        tab[largest] = tab[i];
        tab[i] = swap;
        heapify(tab, largest);
    }
}


int main(){
    int tab[] = {10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10};
    for(int a : tab) cout<<a<<" ";
    cout<<endl;
    build_heap(tab);
    for(int a : tab) cout<<a<<" ";
    cout<<endl;
}