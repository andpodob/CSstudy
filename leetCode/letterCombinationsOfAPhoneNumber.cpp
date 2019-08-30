#include <bits/stdc++.h>

using namespace std;

class Solution {

private:
    bool incrementByOne(int *tab, int *mask, int size){
        int c = 0;
        tab[size-1]+=1;
        for(int i = size-1; i >= 0; i--){
            tab[i]+=(c);
            c = 0;
            if(tab[i] == mask[i]){
                tab[i] = 0;
                c = 1;
            }
        }
        if(c == 1) return true;
        else return false;
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result = {};
        int tab[digits.size()];
        int mask[digits.size()];
        vector<string> keyBoard = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(int i = 0; i < digits.size(); i++){
            mask[i] = keyBoard[digits[i]-'2'].size();
            tab[i] = 0;
        }
        bool stop = false;
        while(!stop){
            string s = "";
            for(int i = 0; i < digits.size(); i++){
                s+=keyBoard[digits[i]-'2'][tab[i]];
            }
            result.push_back(s);
            stop = incrementByOne(tab, mask, digits.size());
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<string> v = s.letterCombinations("32");
    cout<<"[";
    for(string s : v){
        cout<<s<<','<<endl;
    }
    cout<<"]"<<endl;
}