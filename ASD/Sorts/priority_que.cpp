#include <bits/stdc++.h>

#define PARENT(i) i/2
#define LEFT(i) 2*i
#define RIGHT(i) 2*i+1


using namespace std;

//methods that are necessary to implement priority que
void heapify(int*, int);
int maximum(int*);
int extract_max(int*);
void insert(int*, int);


int maximum(int *tab){ 
    return tab[1]; //simply returns root of the heap
}
void heapify(int *tab, int i){
    int temp;
    int largest = i;
    if(LEFT(i) <= tab[0] && tab[LEFT(i)] > tab[largest]){
        largest = LEFT(i);
    }
    if(RIGHT(i) <= tab[0] && tab[RIGHT(i)] > tab[largest]){
        largest = RIGHT(i);
    }
    if(largest != i){
        temp = tab[largest];
        tab[largest] = tab[i];
        tab[i] = temp;
        heapify(tab, largest);
    }
}

int extract_max(int* tab){
    int max;
    if(tab[0] == 0) return -1;
    else{
        max = tab[1];
        tab[1] = tab[tab[0]];
        tab[0]--;
        heapify(tab, 1);
    }
    return max;
}

void insert(int *tab, int key){
    int i;
    tab[0]++; //increasing heap size by one
    i = tab[0];
    while(i > 1 && key > tab[PARENT(i)]){
        tab[i] = tab[PARENT(i)];
        i = PARENT(i);
    }
    tab[i] = key;
}

int main(){
    int tab[101];
    tab[0] = 0;
    for(int i = 0; i < 10; i++) insert(tab, rand()%100); //building heap using insert method
    cout<<"Size: "<<tab[0]<<endl;
    for(int i = 1; i <= tab[0]; i++)cout<<tab[i]<<" ";
    cout<<endl;
    while(tab[0] > 0) cout<<extract_max(tab)<<" "; //extracting maximum one by one cousing sorted output 
    cout<<endl;
}