#include <bits/stdc++.h>

using namespace std;

vector<int> squares;
int** T;

int findOptimal(int n, int i){
    if(n == 0) return 0;
    if(T[n][i] != -1) return T[n][i];
    int a=INT32_MAX, b=INT32_MAX;
    if(n >= squares[i])a=findOptimal(n-squares[i], i)+1;
    if(i > 0)b=findOptimal(n, i-1);
    T[n][i] = min(a,b);
    return T[n][i];
}

class Solution {
public:
    int numSquares(int n);
};

int Solution::numSquares(int n){
    for(int i = 1; i*i <= n; i++)squares.push_back(i*i);
    T = new int*[n+1];
    for(int i = 0; i < n+1; i++)T[i] = new int[squares.size()];
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < squares.size(); j++){
            T[i][j]=-1;
        }
    }
    return findOptimal(n, squares.size()-1);
}

int main(){
    Solution s;
    cout<<s.numSquares(274)<<endl;
}