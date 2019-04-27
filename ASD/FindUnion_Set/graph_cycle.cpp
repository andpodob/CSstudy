#include <bits/stdc++.h>

using namespace std;

struct findUnionSet{
    int *parent;
    findUnionSet(int n){
        parent = new int[n];
        for(int i = 0; i < n; i++)parent[i]=-1;
    }
    
    int find(int a){
        while(parent[a] >= 0)a=parent[a];
        return a;
    }

    void unionSets(int a, int b){
        a = find(a);
        b = find(b);
        parent[a] += parent[b];
        parent[b] = a;
    }
};

struct Graph{
    int Edges = 0;
    int Verticies = 0;
    vector<int> *adj;
    
    Graph(int verticies){
        Verticies = verticies;
        adj = new vector<int>[Verticies];
    }

    void addEdge(int a, int b){
        Edges++;
        adj[a].push_back(b);
        //adj[b].push_back(a);
    }
};


bool checkForCycles(Graph *g){
    int a, b;
    findUnionSet *set = new findUnionSet(g->Verticies);
    for(int i = 0; i < g->Verticies; i++){
        for(int j = 0; j < g->adj[i].size(); j++){
            a = set->find(i);
            b = set->find(g->adj[i][j]);
            if(a >= 0 && a == b)return true;
            set->unionSets(a,b);
        }
    }
    return false;
}

int main(){
    int n = 0;
    int m = 0;
    cin>>n;//how many verticies
    Graph *g = new Graph(n);
    cin>>m;//how many edges
    for(int i = 0; i < m; i++){
        int a;cin>>a;
        int b;cin>>b;
        if(a < n && b < n){
            g->addEdge(a,b);
        }else{
            cout<<"Edge must be in range od 0...n-1"<<endl;
            i--;
        }
    }
    cout<<checkForCycles(g)<<endl;
}