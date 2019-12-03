#include <bits/stdc++.h>

using namespace std;

pair<int, int> findItems(vector<int> v, int credit){
	pair<int, int> result;
    unordered_map<int, int> priceIndexMap;
	for(int i = 0; i < v.size(); i++){
		if(priceIndexMap.find(credit-v[i]) == priceIndexMap.end()){
			priceIndexMap[v[i]] = i;
		}else{
			return make_pair(priceIndexMap[credit-v[i]], i);
		}
	}
}
int main(){
	int N;
	int C;
	int I;
	int itemVal;
	vector<int> items;
	pair<int,int> result;

	cin>>N;
	for(int i = 0; i < N; i++){
		cin>>C;
		cin>>I;
        items.clear();
		for(int i = 0; i < I; i++){
			cin>>itemVal;
			items.push_back(itemVal);
		}
		result = findItems(items, C);
		cout<<result.first+1<<" "<<result.second+1<<endl;
	}
}
