#include<bits/stdc++.h>


using namespace std;
const int NIL =0;

class BipGraph{
  int k,n;
  vector<vector<int>> adj;

  int *pairs, *distance;

  public:
    BipGraph(int n, int k);
    void addEdge(int u, int v);
    bool bfs();
    bool dfs(int u);
    void hopcroftKarp();

};

BipGraph::BipGraph(int n,  int k){
  this->n=n;
  this->k=k;
  for(int i = 0; i < n+1; i++){
    vector<int> t;
    adj.push_back(t);
  }
}

void BipGraph::addEdge(int u, int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}

bool BipGraph::bfs(){
  queue <int>  queue;
  int v;
  int u;
  for(u=1; u <= n; u++){
    if(pairs[u] == NIL){
      distance[u]=0;
      queue.push(u);
    }
    else distance[u]=INT_MAX;
  }

  distance[NIL]=INT_MAX;
  while(!queue.empty()){
    u=queue.front();
    queue.pop();
    if(distance[u]<distance[NIL]){
      for(int i = 0; i < adj[u].size();i++){
        v = adj[u][i];
        if(distance[pairs[v]]==INT_MAX){
          distance[pairs[v]] = distance[u]+1;
          queue.push(pairs[v]);
        }
      }
    }
  }

  return (distance[NIL]!=INT_MAX);
}

bool BipGraph::dfs(int u){
  if (u!=NIL){
    int v;
    for (int i = 0; i < adj[u].size(); i++){
      v = adj[u][i];
      if(distance[pairs[v]]==distance[u]+1){
        if (dfs(pairs[v])){
          pairs[u]=v;
          pairs[v]=u;
          return true;
        }
      }
    }
    distance[u]=INT_MAX;
    return false;
  }
  return true;
}

void BipGraph::hopcroftKarp(){

  pairs=new int[n+1];
  distance=new int[n+1];

  for (int v=0; v<n; v++)
    pairs[v] = NIL;

    int result=0;

    while(bfs()){
      for (int u=1; u<n; u++)
        if(pairs[u]==NIL  && dfs(u))
        result++;
    }
    cout<<result<<"\n";
    for (int i=1; i<=n; i++){
      if(pairs[i]!=NIL)

      {
        cout<<i-1<<" "<<pairs[i]-1<<"\n";
        pairs[pairs[i]]=NIL;
      }
    }

}



int main(){

  string name;
  cin>>name;
  int n,k;
  cin>>n>>k;
  BipGraph G(n,k);
  for (int i=0; i<k; i++){
    int id;
    cin>>id;
  }
  int m;
  cin>>m;
  int a,b;
  for (int i=0; i<m; i++){
    cin>>a;
    cin>>b;
    G.addEdge(a+1,b+1);
  }

  G.hopcroftKarp();
}