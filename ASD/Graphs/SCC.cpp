#include <bits/stdc++.h>

using namespace std;

/*
    Strongly connected components in directed graph.
 */

enum color{
    WHITE, GREY, BLACK
};

struct Graph{
    int N;
    int *color;
    int *visited;
    bool **adj;
    stack<int> S;

    Graph(int N){
        this->N = N;
        color = new int[N];
        for(int i = 0; i < N; i++){
            color[i] = WHITE;

        }
        adj = new bool*[N];
        for(int i = 0; i < N; i++){
            adj[i] = new bool[N];
            for(int j = 0; j < N; j++){
                adj[i][j] = false;
            }
        }
    }

    void addEdge(int from, int to){
        adj[from][to] = true; 
    }

    void transpose(){
        bool **newAdj = new bool*[N];
        for(int i = 0; i < N; i++){
            newAdj[i] = new bool[N];
        }
        for(int i= 0; i < N; i++){
            for(int j = 0; j < N; j++){
                newAdj[i][j] = adj[j][i];
            }
        }
        for(int i = 0; i < N; i++){
            delete[] adj[i];
        }
        delete[] adj;
        adj = newAdj;
    }

    void DFS(int vertex, bool print){
        if(color[vertex] == GREY || color[vertex] == BLACK) return;
        else{
            color[vertex] = GREY;
            for(int i = 0; i < N; i++){
                if(adj[vertex][i] == true){
                    DFS(i, print);
                }
            }
            if(print)cout<<vertex<<" ";
            color[vertex] = BLACK;
            if(!print)S.push(vertex);
        }
    }

    void fillOrder(){
        for(int i = 0; i < N; i++){
            if(color[i] == WHITE){
                DFS(i, false);
            }
        }
    }

    void SCC(){
        fillOrder();
        for(int i = 0; i < N; i++){
            color[i] = WHITE;
        }
        transpose();
        while(!S.empty()){
            int v = S.top();
            S.pop();
            if(color[v] == WHITE){
                DFS(v, true);
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g(5); 
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 
  
    cout << "Following are strongly connected components in "
            "given graph \n"; 
    g.SCC(); 
  
    return 0; 
}