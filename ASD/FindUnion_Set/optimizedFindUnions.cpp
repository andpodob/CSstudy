#include <bits/stdc++.h>

using namespace std;


int find(int parents[], int a){
    //path compression
    if(parents[a] >= 0){
        parents[a] = find(parents, parents[a]);
        return parents[a];
    }
    return a;
}

void unionSets(int parents[], int a, int b){
    a = find(parents, a);
    b = find(parents, b);
    if(parents[a] <= parents[b]){
        parents[a]+=parents[b];
        parents[b] = a;
    }else{
        parents[b]+=parents[a];
        parents[a] = b;
    }
}


int main(){

}