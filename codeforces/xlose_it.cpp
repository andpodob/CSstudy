#include <bits/stdc++.h>

using namespace std;

int LCS(int *A, int *B, int n, int m){
    int dp[n+1][m+1];
    for(int i = 1; i < n+1; i++){
        dp[i][0] = 0;
    }
    for(int i = 1; i < m+1; i++){
        dp[0][i] = 0;
    }
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else if(A[i-1] != B[j-1]){
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    return dp[n][m];
}

void crossOut(int *A, int *B, int n, int m){
    int j = 0;
    for(int i = 0; i < m; i++){
        while(j < n and A[j] != B[i])j++;
        A[j] = -1;
    }
}

int countChanges(int *A, int n){
    int changesCount = 0;
    int B[6] = {4,8,15,16,23,42};
    while(LCS(A, B, n, 6) == 6){
        crossOut(A,B, n, 6);
    }
    for(int i = 0; i < n; i++)if(A[i] != -1)changesCount++;

    return changesCount;
}

int main(){
    int n;cin>>n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin>>A[i];
    }
    cout<<countChanges(A,n)<<endl;
}