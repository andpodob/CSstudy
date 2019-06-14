#include <bits/stdc++.h>

using namespace std;

struct adjList{
    int vertex;
    adjList* next;
};

void addToList(adjList *&, adjList*);

struct Graph{
    int V, E;
    adjList **adj;
    int **w;//edges weight

    Graph(int V){
        adj = new adjList*[V];
        w = new int*[V];
        for(int i = 0; i < V; i++){
            adj[i] = NULL;
            w[i] = new int[V];
        }
        
    }

    void addEgde(int v, int u, int weight){ //undirected graph
        adjList *v1 = new adjList;
        adjList *v2 = new adjList;
        v1->vertex = v;
        v2->vertex = u;
        addToList(adj[v], v2);
        addToList(adj[u], v1);
        w[v][u] = weight;
        w[u][v] = weight;
    }
};

void addToList(adjList* &list, adjList* vertex){
    vertex->next = list;
    list = vertex;
}

void printList(adjList* list){
    while(list != NULL){
        cout<<list->vertex<<" ";
        list = list->next;
    }
    cout<<endl;
}



void initializeSingleSource(Graph *g, int source, int parents[], int distances[]){
    for(int i = 0; i < g->V; i++){
        parents[i] = -1;
        distances[i] = INT32_MAX; 
    }
    distances[source] = 0;
}

void relax(int u, int v, int **w, int *d, int *p){
    if(d[u]+w[u][v] < d[v]){
        p[v]=u;
        d[v]=d[u]+w[u][v];
    }
}

int main(){
    adjList *l = NULL;
    adjList *temp;
    for(int i = 0; i<100; i++){
        temp = new adjList;
        temp->vertex = rand()%100;
        addToList(l, temp);
    }
    printList(l);
}