#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void insertPElement(vector<int> &nums, int p){
        for(; p+1 < nums.size() && nums[p] > nums[p+1]; p++)swap(nums[p], nums[p+1]);
    }
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return;
        int i = nums.size()-2, j = nums.size()-1;
        for(i = nums.size()-2; i >= 0 && nums[i] >= nums[nums.size()-1]; i--){
            insertPElement(nums, i);
        }
        while( i >= 0 && nums[i] < nums[j])j--;
        
        if(i >= 0 ){
            swap(nums[i], nums[j+1]);
        }
    }
};

int main(){
    Solution s;
    //vector<int> test1 = {1,3,2};
    //vector<int> test1 = {2,3,1};
    //vector<int> test1 = {1,1};
    vector<int> test1 = {1,1,5};
    for(int i = 0; i < test1.size(); i++)cout<<test1[i]<<" ";
    cout<<endl;
    s.nextPermutation(test1);
    for(int i = 0; i < test1.size(); i++)cout<<test1[i]<<" ";
    cout<<endl; 
}