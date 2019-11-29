#include <bits/stdc++.h>

using namespace std;

void nextPermutation(vector<int>& v){
    int i = v.size()-1;
    int temp = 0;
    while(i > 0 and v[i-1] > v[i]){
        i--;
    }
    reverse(v.begin()+i, v.end());
    if(i > 0){
        temp = i-1;
        while(v[temp] > v[i]){
            i++;
        }
        swap(v[temp], v[i]);
    }
}


int main(){
    vector<int> v = {1,2,3,4};
    for(int i = 0; i < 24; i++){
        for(int j = 0; j < 4; j++){
            cout<<v[j]<<" ";
        }
        cout<<endl;
        nextPermutation(v);
    }
}