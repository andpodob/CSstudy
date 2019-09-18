#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        int j = 0, possibleStart, c = haystack.size()-needle.size()+1;
        for(int i = 0; i < c; i++){
            possibleStart = i;
            while(i < haystack.size() && j < needle.size() && haystack[i] == needle[j]){
                i++;
                j++;
            }
            if(j == needle.size()) return possibleStart;
            j = 0;
            i = possibleStart;
        }
        return -1;
    }
};

int main(){
    Solution s;
    cout<<s.strStr("mississippi","issip")<<endl;
    cout<<s.strStr("aaaaa", "aab")<<endl;
    cout<<s.strStr("hello", "")<<endl;
}