#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string result = "";
        int n = (numRows -1)*2;
        int start1, start2;
        if(s.size() <= numRows || numRows == 1){
            return s;
        }
        for(int i = 0; i < numRows; i++){
            start1 = i; start2 = n - i;
            if(start1+n != start2 && start1 != start2){
                for(int j = start1, k = start2; j < s.size(); j+=n){
                    result += s.substr(j, 1);
                    if(k < s.size()){
                        result += s.substr(k, 1);
                    }
                    k+=n;
                }
            }else{
                for(int j = start1; j < s.size(); j+=n){
                    result += s.substr(j, 1);
                }
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    cout<<s.convert("A",1)<<endl;
}