#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int binarySearch(int p, int q, vector<int> nums, int target){
        int mid = (p+q)/2;
        while(p < q && p != q-1){
            if(target == nums[mid]) return mid;
            else if(target > nums[mid]) p = mid;
            else q = mid;
            mid = (p+q)/2;
        }
        if(p < nums.size() && target == nums[p]) return p;
        if(q >= 0 && target == nums[q]) return q;
        else return -1;
    }
    int findShift(vector<int> nums){
        int p = 0;
        int s = nums.size();
        while(s>0){
            if(p+s/2 < nums.size() && nums[p] < nums[p+s/2]){
                p += s/2;
            }
            else if(p+s/2 < nums.size()-1 && nums[p] < nums[p+s/2+1]){
                p += s/2+1;
            }
            else s = s/2;
        }
        return (p+1)%nums.size();
    }
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int pivot = findShift(nums);
        int idx1 = binarySearch(0, pivot-1, nums, target);
        int idx2 = binarySearch(pivot, nums.size()-1, nums,  target);
        if(idx1 == idx2 == -1){
            return -1;
        }else{
            return (idx1 != -1)?idx1:idx2; 
        }
    }
};

int main(){
    Solution s;
    // vector<int> v1 = {0,1,2,4,5,6};
    // vector<int> v2 = {6,0,1,2,4,5};
    // vector<int> v3 = {5,6,0,1,2,4};
    // vector<int> v4 = {4,5,6,0,1,2};
    // vector<int> v5 = {2,4,5,6,0,1};
    // vector<int> v6 = {1,2,4,5,6,0};
    // //cout<<s.findShift(v0)<<endl;
    // cout<<s.findShift(v1)<<endl;
    // cout<<s.findShift(v2)<<endl;
    // cout<<s.findShift(v3)<<endl;
    // cout<<s.findShift(v4)<<endl;
    // cout<<s.findShift(v5)<<endl;
    // cout<<s.findShift(v6)<<endl;
    // vector<int> v0 = {0,1,2,4,5,6,7};
    // vector<int> v1 = {7,0,1,2,4,5,6};
    // vector<int> v2 = {6,7,0,1,2,4,5};
    // vector<int> v3 = {5,6,7,0,1,2,4};
    // vector<int> v4 = {4,5,6,7,0,1,2};
    // vector<int> v5 = {2,4,5,6,7,0,1};
    // vector<int> v6 = {1,2,4,5,6,7,0};
    // cout<<s.findShift(v0)<<endl;
    // cout<<s.findShift(v1)<<endl;
    // cout<<s.findShift(v2)<<endl;
    // cout<<s.findShift(v3)<<endl;
    // cout<<s.findShift(v4)<<endl;
    // cout<<s.findShift(v5)<<endl;
    // cout<<s.findShift(v6)<<endl;
    // vector<int> nums = {4,5,6,7,0,1,2};
    vector<int> nums = {1};
    cout<<s.search(nums, 3);
}