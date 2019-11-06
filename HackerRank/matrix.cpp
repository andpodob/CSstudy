#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
vector<int> bfs(vector<vector<pair<int, int>>>& adj, vector<int>& parent, vector<int>& weight){
    vector<int> leafs;
    vector<bool> visited(parent.size(), false);
    queue<int> q;
    
    visited[0] = true;
    q.push(0);
    int v, counter = 0;
    while (q.size() > 0)
    {
        v = q.front();
        q.pop();
        counter = 0;
        for(int i = 0; i < adj[v].size(); i++){
            if(!visited[adj[v][i].first]){
                visited[adj[v][i].first] = true;
                q.push(adj[v][i].first);
                parent[adj[v][i].first] = v;
                weight[adj[v][i].first] = adj[v][i].second;
                counter++;
            }
        }
        if(counter == 0) leafs.push_back(v);
    }
    return leafs;
}
// Complete the minTime function below.
int minTime(vector<vector<int>> roads, vector<int> machines, int n) {
    int minToRet = 0;
    vector<int> parent(n, -1);
    vector<int> color(n, 0);
    vector<int> weight(n, 0);
    vector<int> counter(n, 0);
    vector<pair<int, int>> minInV(n, make_pair(-1, INT_MAX));
    vector<vector<pair<int, int>>> adj(n);

    for(int i = 0; i < machines.size(); i++){
        color[machines[i]] = 1;
    }

    int u, v, w;
    for(int i = 0; i < roads.size(); i++){
        u = roads[i][0];
        v = roads[i][1];
        w = roads[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> leafs = bfs(adj, parent, weight);
    pair<int, int> m;

    for(int i = 0; i < leafs.size(); i++){
        v = leafs[i];
        while(color[v] !=1 && parent[v] != -1){
            v = parent[v];
        }
        m = make_pair(0, INT_MAX);
        while (parent[v] != -1)
        {
            m = (weight[v] < m.second)?make_pair(v, weight[v]):m;
            if(color[parent[v]] == 0){   
                if(minInV[parent[v]].first == -1 || parent[minInV[parent[v]].first] == -1){
                    minInV[parent[v]] = m;
                    v = parent[v];
                }else{
                    if(minInV[parent[v]].second < m.second){
                        minToRet+=minInV[parent[v]].second;
                        u = minInV[parent[v]].first;
                        v = parent[v];
                        parent[u] = -1;
                        minInV[v] = m;
                    }else{
                        minToRet+=m.second;
                        u = m.first;
                        v = parent[v];
                        parent[u] = -1;
                        m = minInV[v];
                    }
                }
            }else{
                minToRet += m.second;
                u = m.first;
                v = parent[v];
                parent[u] = -1;
                m = make_pair(v,weight[v]);
                // break;
            }
        }
    }

    return minToRet;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    vector<vector<int>> roads(n - 1);
    for (int i = 0; i < n - 1; i++) {
        roads[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> roads[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> machines(k);

    for (int i = 0; i < k; i++) {
        int machines_item;
        cin >> machines_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        machines[i] = machines_item;
    }

    int result = minTime(roads, machines, n);

    fout << result << "\n";
    cout<<result<<endl;
    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';
    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
