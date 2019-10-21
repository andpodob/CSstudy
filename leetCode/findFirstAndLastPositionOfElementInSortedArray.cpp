#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int binSearchLower(vector<int>& nums, int target){
        int p = 0;
        int q = nums.size()-1;
        int mid;

        while(p < q-1){
            mid = (p+q)/2;
            if(nums[q] >= nums[mid] && nums[mid] >= target){
                q = mid;
            }else{
                p = mid;
            }
        }
        return q;
    }

    int binSearchUpper(vector<int>& nums, int target){
        int p = 0;
        int q = nums.size()-1;
        int mid;
        while(p < q-1){
            mid = (p+q)/2;
            if(nums[p] <= nums[mid] && nums[mid] <= target){
                p = mid;
            }else{
                q = mid;
            }
        }
        return p;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {0,0};
        result[0] = binSearchLower(nums, target);
        result[1] = binSearchUpper(nums, target);
        return result;
    }
};


int main(){
    Solution s;
    vector<int> input = {5,7,7,8,8,10};
    vector<int> output = s.searchRange(input, 8);
    cout<<output[0]<<" "<<output[1]<<endl;
}