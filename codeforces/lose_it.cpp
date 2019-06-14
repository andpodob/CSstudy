#include <bits/stdc++.h>

/*
    Here is solution for problem lose it! from codeforces: https://codeforces.com/contest/1176/problem/C
 */

using namespace std;


int sequence[6] = {4,8,15,16,23,42};

int countChanges(int *A, int n){
    int cnt[6];
    for(int i = 0; i < 6; i++)cnt[i] = 0;
    for(int i = 0; i < n; i++){
        switch (A[i])
        {
        case 4:
            cnt[0]++;
            break;
        case 8:
            if(cnt[0] > 0){
                cnt[0]--;
                cnt[1]++;
            }
            break;
        case 15:
            if(cnt[1] > 0){
                cnt[1]--;
                cnt[2]++;
            }
            break;
        case 16:
            if(cnt[2] > 0){
                cnt[2]--;
                cnt[3]++;
            }
            break;
        case 23:
            if(cnt[3] > 0){
                cnt[3]--;
                cnt[4]++;
            }
            break;
        case 42:
            if(cnt[4] > 0){
                cnt[4]--;
                cnt[5]++;
            }
            break;
        }
    }
    return n-6*cnt[5];
}

int main(){
    int n;cin>>n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin>>A[i];
    }
    cout<<countChanges(A,n)<<endl;
}  