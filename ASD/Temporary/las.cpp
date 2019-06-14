#include <bits/stdc++.h>

using namespace std;

int countProfit(int *wood, int n){
    int dp[n];
    dp[0] = wood[0]; //dla lasu z jednym drzewem najbardziej opłaca się je wyciąć
    dp[1] = wood[1]+wood[0]; //dla lasu z dwoma drzewamy najlepiej uciąć je oba
    dp[2] = max(wood[0]+wood[1],max(wood[1]+wood[2],wood[0]+wood[2])); 
    for(int i = 2; i < n; i++){
        dp[i] = max(dp[i-1], max(dp[i-2]+wood[i], dp[i-3]+wood[i-1]+wood[i]));
    }

    return dp[n-1];
}

int main(){

}