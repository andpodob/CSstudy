#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)return 0;
        int p = 0, q = nums.size()-1;
        while(p < q){
            if(nums[p] != val){
                p++;
            }
            if(nums[q] == val) q--;
            if(p < q && nums[p] == val && nums[q] != val) swap(nums[p],nums[q]);
        }
        return (nums[p] == val)?p:p+1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {4,4,4,4,4};
    for(int i = 0; i < nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    int size = s.removeElement(nums,4);
    cout<<size<<endl;
    for(int i = 0; i < size; i++){
        cout<<nums[i]<<" "; 
    }
    cout<<endl;
}