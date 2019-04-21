#include <bits/stdc++.h>

// int input[10001];

// int count(int T[]){
//     int tab[10001][2];
//     for(int i = 0 ; i < 10001; i++)tab[i][0]=tab[i][1]=0;
//     for(int i = 1; i < 10001; i++){
//         tab[i][0] = max(tab[i-1][0], tab[i-1][1]);
//         tab[i][1] = tab[i-1][0] + T[i]*i;
//     }
//     return max(tab[10000][0], tab[10000][1]);
// }

// int main(){
//     int n, a; cin>>n;
//     for(int i = 0; i < 10001; i++) input[i]=0;
//     for(int i = 0; i< n; i++){
//         cin>>a;
//         input[a]++;
//     }
//     cout<<count(input)<<endl;
// }
using namespace std;

int input[10001];

int count(){
    int tab[10001][2];
    for(int i = 0 ; i < 10001; i++)tab[i][0]=tab[i][1]=0;
    for(int i = 1; i < 10001; i++){
        tab[i][0] = max(tab[i-1][0], tab[i-1][1]);
        tab[i][1] = tab[i-1][0] + input[i]*i;
    }
    return max(tab[10000][0], tab[10000][1]);
}

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        for(int i = 0; i < 10001; i++) input[i]=0;S
        for(int i = 0; i< nums.size(); i++){
            input[nums[i]]++;
        }
        return count();
    }
};


int main(){
    Solution temp;
    vector<int> x;
    int n,a; cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a;
        x.push_back(a);
    }
    cout<<temp.deleteAndEarn(x)<<endl;
}