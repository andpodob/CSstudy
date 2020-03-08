#include <bits/stdc++.h>

using namespace std;

struct less_than_key
{
    inline bool operator() (const pair<int, int>& key1, const pair<int, int>& key2)
    {
        if(key1.second == -1 and key2.second == -1){
			return key1.first < key2.first;
		}else if(key1.second == -1){
			return false;
		}else if(key2.second == -1){
			return true;
		}else{
			return key1.second < key2.second;
		}
    }
};

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> positions;
		for(int i = 0; i < arr2.size(); i++){
			positions[arr2[i]] = i;
		} 
		vector<pair<int, int>> num_pos;
		for(int i = 0; i < arr1.size(); i++){
			if(positions.find(arr1[i]) != positions.end()){
				num_pos.push_back(make_pair(arr1[i], positions[arr1[i]]));
			}else{
				num_pos.push_back(make_pair(arr1[i], -1));
			}
		}
		sort(num_pos.begin(), num_pos.end(), less_than_key());
		for(int i = 0; i < arr1.size(); i++){
			arr1[i] = num_pos[i].first;
		}

		return arr1;
    }
};

int main(){
	vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
	vector<int> arr2 = {2,1,4,3,9,6};
	Solution s;
	vector<int> result = s.relativeSortArray(arr1, arr2);

	for(int i =0; i < result.size(); i++){
		cout<<result[i]<<" ";
	}
	cout<<endl;
}
