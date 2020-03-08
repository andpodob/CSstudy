#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int cmax=arr1[0];
        int cmin=arr1[0];
        for (int i = 0; i < arr1.size(); i++){
            if (arr1[i]>cmax){
                cmax=arr1[i];
            }
            if (arr1[i]<cmin){
                cmin=arr1[i];
            }
        }

        vector<int> liczniki(cmax-cmin+1, 0);

        int adr = 0;

        for (int i = 0; i < arr1.size();i++){
            adr = arr1[i]-cmin;
            liczniki[adr]++;// = liczniki[adr]+1;
        }

        vector<int> result;
    
        for( int i = 0; i < arr2.size();i++ ){
            while(liczniki[arr2[i]-cmin]>0){
                result.push_back(arr2[i]);
                liczniki[arr2[i]-cmin] --;
            }
        }
        for(int i = 0; i < liczniki.size();i++){
            while(liczniki[i] > 0){
                result.push_back(i+cmin);
                liczniki[i]--;
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};
    vector<int> res = s.relativeSortArray(arr1, arr2);

    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}