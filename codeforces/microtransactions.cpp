#include <bits/stdc++.h>

using namespace std;


int main(){
    int n, m;
    cin>>n;cin>>m;
    int burle[2*n+1];
    int spent = 0;
    int toBuy[m+1];
    vector<int> sales[2*n+1];
    for(int i = 0; i<2*n;i++)burle[i+1]=i+1;
    for(int i = 0; i < n; i++){
        cin>>toBuy[i];
    }
    int a,b;
    for(int i = 0; i < m; i++){
        cin>>a; cin>>b;
        if(toBuy[b] != 0 and a <= 2*n)sales[a].push_back(b);
    }

    for()
}  