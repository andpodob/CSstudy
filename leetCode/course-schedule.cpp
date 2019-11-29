#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool contains_cycle(vector<vector<int>>& adj, vector<int>& color, int node){
        color[node] = 1;
        for(int i = 0; i < adj[node].size(); i++){
            if(color[adj[node][i]] == 1) return true;
            if(color[adj[node][i]] == 0 and contains_cycle(adj, color, adj[node][i])) return true;
        }
        color[node] = 2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> color(numCourses, 0);
        
        for(int i = 0; i < numCourses; i++){
            if(color[i] == 0){
                if(contains_cycle(adj, color, i)) return false;
            }
        }
        
        return true;
    }
};

int main(){
    int in1 = 2;
    vector<vector<int>> in2 = {{0,1},{1,0}};
    Solution s;
    cout<<s.canFinish(in1, in2)<<endl;
}