#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p = 0;
        int q = 1;
        for(; q <= nums.size(); q++){
            while(q < nums.size() && nums[q-1] == nums[q])q++;
            nums[p++] = nums[q-1];
        }
        return p;
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,0};
    for(int i = 0; i < nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    int size = s.removeDuplicates(nums);
    cout<<size<<endl;
    for(int i = 0; i < size; i++){
        cout<<nums[i]<<" "; 
    }
    cout<<endl;
}