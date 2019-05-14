#include <bits/stdc++.h>

using namespace std;

int find(int *parent, int a){
    int temp = a;
    int b;
    while(parent[a] >= 0){
        a=parent[a];
    }
    while(temp != a){
        b = parent[temp];
        parent[temp]=a;
        temp = b;
    }
    return a;
}

void unionSets(int *parent, int a, int b){
    a = find(parent, a);
    b = find(parent, b);
    if(parent[a] <= parent[b]){
        parent[a]+=parent[b];
        parent[b]=a;
    }else{
        parent[b]+=parent[a];
        parent[a]=b;
    }
}

int count_places(bool *possible[], int N, int X, int Y){
    int parent[N*N];
    for(int i = 0; i < N*N; i++)parent[i] = -1;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            if(possible[x][y] == true){
                if(x < N-1 && possible[x+1][y] == true){
                    unionSets(parent, x*N+y, (x+1)*N+y);
                }   
                if(y < N-1 && possible[x][y+1] == true){
                    unionSets(parent, x*N+y, x*N+y+1);
                }
            }
        }
    }
    
    return (-1)*parent[find(parent,X*N+Y)];
}

int main(){
    bool *possible[3];
    possible[0] = new bool[3];
    possible[1] = new bool[3];
    possible[2] = new bool[3];

    possible[0][0] = true;
    possible[0][1] = false;
    possible[0][2] = false;
    possible[1][0] = true;
    possible[1][1] = true;
    possible[1][2] = false;
    possible[2][0] = false;
    possible[2][1] = true;
    possible[2][2] = true;

    cout<<count_places(possible,3,0,0)<<endl;
}