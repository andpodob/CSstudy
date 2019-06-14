#include <bits/stdc++.h>

using namespace std;

struct Edge{
    int from;
    int to;
    int weigth;

    Edge(int from, int to, int weigth){
        this->from = from;
        this->to = to;
        this->weigth = weigth;
    }
};

struct Graph{
    int E, V;
    int i;
    Edge **edges;

    Graph(int E, int V){
        this->i = 0;
        this->E = E;
        this->V = V;
        this->edges = new Edge*[E];
    }

    void addEdge(int from, int to, int weigth){
        Edge *e = new Edge(from, to, weigth);
        edges[i] = e;
        i++;
    }
};

int find(int parents[], int a){
    //path compression
    if(parents[a] >= 0){
        parents[a] = find(parents, parents[a]);
        return parents[a];
    }
    return a;
}

int unionSets(int parents[], int a, int b){
    a = find(parents, a);
    b = find(parents, b);
    if(parents[a] <= parents[b]){
        parents[a]+=parents[b];
        parents[b] = a;
        return a;
    }else{
        parents[b]+=parents[a];
        parents[a] = b;
        return b;
    }
}

int comparator(Edge* const a, Edge* const b) 
{ 
    return a->weigth < b->weigth; 
} 

void Kruskal(Graph *g){
    int parentA, parentB;
    sort(g->edges, g->edges+(g->E), &comparator);
    int *parents = new int[g->V];
    for(int i = 0; i < g->V; i++){
        parents[i] = -1;
    }
    for(int i = 0; i < g->E; i++){
        parentA = find(parents, g->edges[i]->from);
        parentB = find(parents, g->edges[i]->to);
        if(parentA != parentB){
            unionSets(parents, parentA, parentB);
            cout<<g->edges[i]->from<<" - "<<g->edges[i]->to<<endl;
        }
    }
}

int main(){
    Graph *g = new Graph(3, 3);

    g->addEdge(0,1,10);
    g->addEdge(1,2,1);
    g->addEdge(2,0,20);

    for(int i = 0; i < 3; i ++){
        cout<<g->edges[i]->weigth<<" ";
    }

    cout<<endl;

    Kruskal(g);

}