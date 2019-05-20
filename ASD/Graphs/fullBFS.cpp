#include <bits/stdc++.h>

using namespace std;

enum c{
    WHITE, GREY, BLACK
};

struct Vertex {
    int d;
    c color;
    Vertex* p = NULL;
};

struct Graph{
    vector<Vertex*> v;
    vector<int> *adj;
    Graph(int N){
        adj = new vector<int>[N];
        for(int i = 0; i < N; i++){
            v.push_back(new Vertex());
        }
    }
    void addEdge(int a, int b){
        adj[a].push_back(b);
    }
};

void BFS(Graph* g, int s){
    for(int i = 0; i <g->v.size(); i++){
        g->v[i]->color = WHITE;
        g->v[i]->d = INT32_MAX;
        g->v[i]->p = NULL;
    }

    g->v[s]->color = GREY;
    g->v[s]->p = NULL;
    g->v[s]->d = 0;

    queue<int> q;
    q.push(s);
    int u, distance;
    while(!q.empty()){
        u = q.front();
        distance = g->v[u]->d;
        q.pop();
        for(int i = 0; i < g->adj[u].size(); i++){
            if(g->v[g->adj[u][i]]->color == WHITE){
                g->v[g->adj[u][i]]->color = GREY;
                g->v[g->adj[u][i]]->d = distance+1;
                g->v[g->adj[u][i]]->p = g->v[u];
                q.push(g->adj[u][i]);
            }
        }
        g->v[u]->color = BLACK;
    }
}


int main(){
    Graph *g = new Graph(8);

    g->addEdge(0,1);
    g->addEdge(1,0);

    g->addEdge(1,2); 
    g->addEdge(2,1);

    g->addEdge(2,3);
    g->addEdge(3,2);

    g->addEdge(3,4);
    g->addEdge(4,3);

    g->addEdge(3,5); 
    g->addEdge(5,3);

    g->addEdge(4,5);
    g->addEdge(5,4);

    g->addEdge(5,7);
    g->addEdge(7,5);

    g->addEdge(7,6); 
    g->addEdge(6,7);

    g->addEdge(4,6);
    g->addEdge(6,4);
    
    BFS(g,2);
    //distances
    for(int i = 0; i < g->v.size(); i++){
        cout<<i<<": "<<g->v[i]->d<<endl;
    }
}