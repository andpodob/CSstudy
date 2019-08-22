#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x == 0)return 0;
        int range = pow(2,28);
        int sign = (x < 0 )?-1:1;
        int a = 0, result = 0;
        while(x != 0){
            a = x%10;
            x  = x/10;
            if(result/2 >= range)return 0;
            result*=10;
            result += abs(a);
        }
        return sign*result;
    }
};

int main(){
    Solution s;
    cout<<s.reverse(1534236469)<<endl;
}