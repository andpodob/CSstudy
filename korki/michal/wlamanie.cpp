#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int num[n];
    
    for(int i = 0; i < n; i++){
        cin>>num[i];
    }

    sort(num, num+n);

    int skradzione = 0;
    for(int i = 1; i < n; i++){
        skradzione += num[i]-num[i-1]-1;
    }

    cout<<skradzione<<endl;

}

