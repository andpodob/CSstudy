#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int width = height.size()-1;
        int p = 0, q = height.size()-1;
        int volume = 0;
        int maxVolume = 0;
        int maxHeight = 0;
        for(int i = 0; i < height.size()-1; i++)
            if(height[i] > maxHeight) maxHeight = height[i];
            
        for(int level = 1; level <= maxHeight; level++){
            while(p < q && height[p] < level){
                p++;
                volume-=(level-1);
            }
            while(p < q && height[q] < level){
                q--;
                volume-=(level-1);
            }
            volume+=(q-p);
            if(volume > maxVolume) maxVolume = volume;
        }
        return volume;
    }
};

int main(){
    vector<int> vect{1,8,6,2,5,4,8,3,7}; 
    Solution s;
    cout<<s.maxArea(vect)<<endl;
}