#include <bits/stdc++.h>

using namespace std;

#define NIL 0

bool bipartite(vector<vector<int>>& adj, vector<int>& color){
    queue<int> q;
    int v;
    int u;
    for(int i = 0; i < color.size(); i++){
        if(color[i] == 0){
            color[i] = 1;
            q.push(i);
            while (!q.empty())
            {
                v = q.front(); q.pop();
                for(int j = 0; j < adj[v].size(); j++){
                    u = adj[v][j];
                    if(color[u] == color[v]) return false;
                    if(color[u] == 0){
                        color[u] = -color[v];
                        q.push(u);
                    }
                }
            }  
        }
    }
    return true;
}

bool BFS(vector<int>& U, vector<int>& Pair_U, vector<int>& Pair_V, vector<int>& dist, vector<vector<int>>& adj){
    int u, v;
    queue<int> q;
    for(int i = 0; i < U.size(); i++){
        u = U[i];
        if(Pair_U[u] == NIL){
            dist[u] = 0;
            q.push(u);
        }else{
            dist[u] = INT_MAX;
        }
    }
    dist[NIL] = INT_MAX;
    while (!q.empty())
    {
        u = q.front(); q.pop();
        if(dist[u] < dist[NIL]){
            for(int i = 0; i < adj[u].size(); i++){
                v = adj[u][i];
                if(dist[Pair_V[v]] == INT_MAX){
                    dist[Pair_V[v]] = dist[u] + 1;
                    q.push(Pair_V[v]);
                }
            }
        }
    }
    return dist[NIL] != INT_MAX;
}

bool DFS(int u,vector<int>& Pair_U,vector<int>& Pair_V, vector<vector<int>>& adj, vector<int>& dist){
    int v;
    if(u != NIL){
        for(int i = 0; i < adj[u].size(); i++){
            v = adj[u][i];
            if(dist[Pair_V[v]] == dist[u]+1){
                if(DFS(Pair_V[v], Pair_U, Pair_V, adj, dist)){
                    Pair_V[v] = u;
                    Pair_U[u] = v;
                    return true;
                }
            }
            dist[u] = INT_MAX;
            return false;
        }
    }
    return true;
}

int Hopcroft_Karp(vector<vector<int>>& adj, int n){
    vector<int> color(n+1, 0);
    vector<int> dist(n+1);
    vector<int> U;
    vector<int> V;
    int matching = 0;
    if(bipartite(adj, color)){
            for(int i = 1; i < color.size(); i++){
                if(color[i] == -1){
                    U.push_back(i);
                }
                else
                {
                    V.push_back(i);
                }
            }
            vector<int> Pair_V(n+1);
            vector<int> Pair_U(n+1);

            for(int i = 1; i < U.size(); i++){
                Pair_U[U[i]] = NIL;
            }
            for(int i = 1; i < V.size(); i++){
                Pair_V[V[i]] = NIL;
            }
            int u = 0;
            while (BFS(U, Pair_U, Pair_V, dist, adj) == true){
                for(int i = 0; i < U.size(); i++){
                    u = U[i];
                    if(Pair_U[u] == NIL){
                        if(DFS(u,Pair_U, Pair_V,adj, dist)){
                            matching++;
                        }
                    }
                }
            }   
        }
    return matching;
}

int main(){
    int tmp;
    string BWA;
    cin>>BWA;
    int n;
    cin>>n;
    int k;
    cin>>k;
    for(int i = 0; i < k; i++){
        cin>>tmp;
    }
    int m;
    int a, b;
    cin>>m;
    vector<pair<int, int>> edges;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++){
        cin>>a; cin>>b;
        adj[a+1].push_back(b+1);
        adj[b+1].push_back(a+1);
    }

    cout<<Hopcroft_Karp(adj, n)<<endl;
}

// function Hopcroft-Karp
//     for each u in U
//         Pair_U[u] = NIL
//     for each v in V
//         Pair_V[v] = NIL
//     matching = 0
//     while BFS() == true
//         for each u in U
//             if Pair_U[u] == NIL
//                 if DFS(u) == true
//                     matching = matching + 1
//     return matching

// function DFS (u)
//     if u != NIL
//         for each v in Adj[u]
//             if Dist[ Pair_V[v] ] == Dist[u] + 1
//                 if DFS(Pair_V[v]) == true
//                     Pair_V[v] = u
//                     Pair_U[u] = v
//                     return true
//         Dist[u] = ∞
//         return false
//     return true

// function BFS ()
//     for each u in U
//         if Pair_U[u] == NIL
//             Dist[u] = 0
//             Enqueue(Q,u)
//         else
//             Dist[u] = ∞
//     Dist[NIL] = ∞
//     while Empty(Q) == false
//         u = Dequeue(Q)
//         if Dist[u] < Dist[NIL] 
//             for each v in Adj[u]
//                 if Dist[ Pair_V[v] ] == ∞
//                     Dist[ Pair_V[v] ] = Dist[u] + 1
//                     Enqueue(Q,Pair_V[v])
//     return Dist[NIL] != ∞

