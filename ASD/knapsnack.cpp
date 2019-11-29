#include <bits/stdc++.h>

using namespace std;

int knapsnack(vector<int> v, vector<int> wt, int W){
    int K[v.size()+1][W+1];
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < W+1; j++){
            K[i][j] = 0;
        }
    }

    for(int i = 0; i <= v.size(); i++){
        for(int w = 0; w <= W+1; w++){
            if(wt[i-1] <= w){
                
            }else{

            }
        }
    }
}

// int knapsnack(vector<int> v, vector<int> wt, int W){
//     int K[v.size()][W+1];
//     for(int i = 0; i < v.size(); i++){
//         for(int j = 0; j < W; i++){
//             K[i][j] = -1;
//         }
//     }
//     int w = 0;
//     int v = 0;
//     for(int i = 0; i < v.size(); i++){
//         w += wt[i];
//         v += v[i]
//         if(w <= W){
//             K[i][w] = v;
//         }else{
//             break;
//         }
//     }
//     vector<int> used(v.size(), 0);
//     stack<pair<int, int>> s;
//     K[0][0] = 0;
//     s.push(make_pair(0,0));
//     pair<int, int> t;
//     int M = 0;
//     int m = 0;
//     while(!s.empty()){
//         t = s.top();
//         s.pop();
//         M = max(M, K[t.first][t.second]);
//         if(t.first+1 < v.size()){
//             m = max(K[t.first+1][t.second], K[t.first][t.second]);
//             if(m == K[t.first][t.second]){
//                 s.push(make_pair(t.first+1, t.second));
//             }
//             if(K[t.first][t.second]+wt[t.first] <= W){
//                 if(K[t.first][t.second]+wt[t.first] > K[t.first][t.second+w[t]]){
//                     s.push(make_pair(t.first, t.second+wt[t.first]));
//                 }    
//             }
//         }
//     }
//     return M;
// }

int main(){

}