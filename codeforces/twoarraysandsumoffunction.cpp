#include <bits/stdc++.h>

#define MOD 998244353

using namespace std;

int main(){
    int temp;
    int n; cin>>n;
    long long a[n];
    long long c[n];
    long long b[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n; i++){
        cin>>b[i];
    }

    sort(b, b+n, greater<long long>());
    
    for(int i = 0; i < n; i++){
        c[i] = (i+1)*1ll*(n-i)*a[i];
    }

    sort(c, c+n);

    int result = 0;
    for(int i = 0; i < n; i++){
        result = (result + (c[i] % MOD * 1ll * b[i]) % MOD) % MOD;
    }

    cout<<result;
}