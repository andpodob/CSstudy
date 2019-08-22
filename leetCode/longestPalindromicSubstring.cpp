#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) return "";
        vector<int> vec(s.size(), 1);
        vector<int> vec2(s.size(), 1);
        int a = 0, b = 0, max = 0;
        for(int k = 0; k < s.size()/2+1; k++){
            for(int i = 0; i <  s.size(); i++){
                a = i - vec[i]/2;
                b = i + vec[i]/2+1;
                if(a >= 0 && b < s.size() && s[a] == s[b]){
                    vec[i] = (i == a)?vec[i]+1:vec[i]+2;
                }
                if(vec[i] > vec[max] && vec[i] > vec2[max]) max = i;
            }
            for(int i = 0; i <  s.size(); i++){
                a = i - vec2[i]/2-1;
                b = i + vec2[i]/2+1;
                if(a >= 0 && b < s.size() && s[a] == s[b]){
                    vec2[i]+=2;
                }
                if(vec2[i] > vec2[max] && vec2[i] > vec[max]) max = i;
            }
        }

        for(int i = 0; i <  s.size(); i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;

        for(int i = 0; i <  s.size(); i++){
            cout<<vec2[i]<<" ";
        }
        cout<<endl;

        if(vec2[max] >= vec[max]){
            return s.substr(max-vec2[max]/2, vec2[max]);
        }else{
            return s.substr(max-vec[max]/2+1, vec[max]);
        }
    }
};

int main(){
    Solution s;
    cout<<s.longestPalindrome("tattarrattat")<<endl;
}