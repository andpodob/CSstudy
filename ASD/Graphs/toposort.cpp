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

int DFS(Graph *g, stack<int> *s, int i){
    int res = 0;
    if(g->v[i]->color == WHITE){
        g->v[i]->color = GREY;
        for(int j = 0; j < g->adj[i].size(); j++){
            if(g->v[g->adj[i][j]]->color == GREY) return -1;
            else if(g->v[g->adj[i][j]]->color == WHITE){
                res =  DFS(g, s, g->adj[i][j]);
                if(res == -1) return -1;
            }
        }
    }
    s->push(i);
    g->v[i]->color = BLACK;
    return 1;
}

void topoSort(Graph *g){
    int res = 0;
    stack<int> stack;
    for(int i = 0; i < g->v.size(); i++){
        if(g->v[i]->color == WHITE){
            res = DFS(g, &stack, i);
            if(res == -1){
                cout<<"Graf is not DAG, can not perform topological sort!";
                return;
            }
        }
    }
    while(!stack.empty()){
        res = stack.top();
        stack.pop();
        cout<<res<<" ";
    }
    cout<<endl;
}


int main(){
    Graph *g = new Graph(9);

    g->addEdge(0,1);

    g->addEdge(1,2); 

    g->addEdge(0,3);

    g->addEdge(3,2);

    g->addEdge(4,3);

    g->addEdge(4,6);

    g->addEdge(5,6);

    g->addEdge(5,4);

    g->addEdge(7,6);

    topoSort(g);
}