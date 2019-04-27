#include <bits/stdc++.h>

using namespace std;

int changeMaker(vector<int> coins, int c, int target, int **memoization){
    if(target == 0) return 0;
    else if(memoization[c][target-1] != -1){
        return memoization[c][target-1];
    }else{
        int a = INT32_MAX, b = INT32_MAX;
        if(target >= coins[c]) 
            a = changeMaker(coins, c, target-coins[c], memoization)+1; 
        if(c > 0)
            b = changeMaker(coins, c-1, target, memoization);

        memoization[c][target-1] = min(a,b);
        return memoization[c][target-1];
    }
}

int makeChange(vector<int> coins, int target){
    int **memoization;
    memoization = new int *[coins.size()];
    for(int i = 0; i<coins.size(); i++){
        memoization[i] = new int[target];
        for(int j = 0; j < target; j++)memoization[i][j] = -1;
    }
    return changeMaker(coins, coins.size()-1, target, memoization);
}

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(5);
    v.push_back(12);
    cout<<makeChange(v, 16)<<endl;
}