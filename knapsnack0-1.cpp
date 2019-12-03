#include <bits/stdc++.h>

using namespace std;

int knapsnack(vector<int> v, vector<int> wt, int W){
	int **dp = new int*[v.size()+1];
	for(int i = 0; i <= v.size();i++){
		dp[i] = new int[W+1];
	}
	v.insert(v.begin(), 0);
	wt.insert(wt.begin(), 0);

	for(int i = 0; i < v.size(); i++){
		for(int w = 0; w <= W; w++){
			if(w == 0 or i == 0) dp[i][w] = 0;
			else{
				if(w - wt[i] >= 0){
					dp[i][w]=max(dp[i-1][w], v[i]+dp[i-1][w-wt[i]]);
				}else{
					dp[i][w] = dp[i-1][w];
				}
			}
		}
	}
	return dp[v.size()-1][W];
}

int knapsnack_requ(vector<int>& v, vector<int>& wt, int W, int i, vector<vector<int>>& dp){
	if(W <= 0) return 0;
    if(i >= v.size()) return 0;
    if(dp[i][W] != -1) return dp[i][W];
    if(W-wt[i] < 0){
        dp[i][W] = knapsnack_requ(v, wt, W,i+1,dp);
        return dp[i][W];
    }
    dp[i][W] = max(knapsnack_requ(v, wt, W,i+1,dp), knapsnack_requ(v, wt, W-wt[i],i+1,dp)+v[i]);
	return dp[i][W];
}

int knapsnackv2(vector<int> v, vector<int> wt, int W){
    vector<vector<int>> dp;
    for(int i = 0; i < v.size(); i++){
        vector<int> v(W+1, -1);
        dp.push_back(v);
    }
    return knapsnack_requ(v,wt,W,0,dp);
}

int main(){
    vector<int> value = {110,100,120};
    vector<int> wt = {10,20,30};
    int W = 50;
    cout<<knapsnack(value, wt, W)<<endl;
    cout<<knapsnackv2(value, wt, W)<<endl;
}
