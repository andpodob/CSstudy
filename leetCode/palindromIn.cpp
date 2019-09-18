#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int n = log10(x)+1;
        int p = pow(10,n-1);
        int a = 0, b = 0;
        for(int i = 0; i < n/2; i++){
            a = x/p;
            b = x%10;
            x = x%p;
            x = x/10;
            p = p/100;
            if(a != b) return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    cout<<s.isPalindrome(2045402)<<endl;
}