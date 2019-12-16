#include <bits/stdc++.h>

using namespace std;

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

vector<pair<int, int>> edmunds_karp(vector<pair<int, int>> edges, int n){
    int fmax = 0;
    vector<vector<int>> adj(n);
    vector<int> color(n,0);
    vector<vector<int>> C(n+2);
    vector<vector<int>> F(n+2);
    vector<int> P(n+2);
    vector<int> CFP(n+2);
    queue<int> Q;
    int i = 0;

    for(i = 0; i < n+2; i++){
        vector<int> t(n+2, 0);
        C[i] = t;
        F[i] = t;
    }

    for(i = 0; i < edges.size(); i++){
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    } 

    if(!bipartite(adj, color)){
        return {make_pair(-1,-1)};
    }

    for(int i = 0; i < n; i++){
        if(color[i] == -1){
            for(int j = 0; j < adj[i].size(); j++){
                C[i][j] = 1;
                C[n][i] = 1;
            }
        }else{
            C[i][n+1] = 1;
        }
    }

    int v = 0;
    int u = 0;
    int cp = INT_MAX;
    bool esc;

    fmax = 0;

    while(true)
    {
      for(i = 0; i <= n + 1; i++) P [ i ] = -1;

      P [ n ] = -2;
      CFP [ n ] = INT_MAX;

      while(!Q.empty()) Q.pop();
      Q.push(n);

      esc = false;

      while(!Q.empty())
      {
        v = Q.front(); Q.pop();

        for(u = 0; u <= n + 1; u++)
        {
          cp = C [ v ][ u ] - F [ v ][ u ];
          if(cp && (P [ u ] == -1))
          {
            P [ u ] = v;
            if(CFP [ v ] > cp) CFP [ u ] = cp; else CFP [ u ] = CFP [ v ];
            if(u == n+1)
            {
              fmax += CFP [ n+1 ];
              i = u;
              while(i != n)
              {
                v = P [ i ];
                F [ v ][ i ] += CFP [ n+1 ];
                F [ i ][ v ] -= CFP [ n+1 ];
                i = v;
              }
              esc = true; break;
            }
            Q.push(u);
          }
        }
        if(esc) break;
      }
      if(!esc) break;
    }
    // while(true)
    // {
    //   for(i = 0; i <= n + 1; i++) P [ i ] = -1;

    //   P[n] = -2;
    //   CFP[n] = INT_MAX;

    //   q.push(n);

    //   esc = false;

    //   while(!q.empty())
    //   {
    //     v = q.front(); q.pop();

    //     for(u = 0; u <= n + 1; u++)
    //     {
    //       cp = C[v][u] - F[v][u];
    //       if(cp && (P[u] == -1))
    //       {
    //         P [u] = v;
    //         if(CFP[v] > cp) CFP[u] = cp; else CFP[u] = CFP[v];
    //         if(u == n+1)
    //         {
    //           fmax += CFP[n+1];
    //           i = u;
    //           while(i != n)
    //           {
    //             v = P [i];
    //             F[v][i] += CFP[n+1];
    //             F[i][v] -= CFP[n+1];
    //             i = v;
    //           }
    //           esc = true; break;
    //         }
    //         q.push(u);
    //       }
    //     }
    //     if(esc) break;
    //   }
    //   if(!esc) break;
    // }

    vector<pair<int, int>> result;
    if(fmax > 0)
      for(v = 0; v < n; v++)
        for(u = 0; u < n; u++)
          if((C[v][u] == 1) && (F[v][u] == 1))
            result.push_back(make_pair(v,u));

    return result;
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
    for(int i = 0; i < m; i++){
        cin>>a; cin>>b;
        edges.push_back(make_pair(a,b));
    }

    vector<pair<int, int>> matching = edmunds_karp(edges, n);
    cout<<matching.size()<<endl;
    for(int i = 0; i < matching.size(); i++){
        cout<<matching[i].second<<" "<<matching[i].first<<endl;
    }
}

