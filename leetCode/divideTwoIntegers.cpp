#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 0;
        int divisorCopy;
        int sign = ((dividend<0 && divisor>0)||(dividend>0 && divisor<0))?-1:1;
        if(dividend == 0) return 0;
        if(divisor == dividend)return 1;
        if(divisor == INT_MIN) return 0;
        if(dividend == INT_MIN && divisor == -1)return INT_MAX;
        if(abs(divisor) == 1)return (divisor<0)?-dividend:dividend;
        divisor = abs(divisor);
        while(divisor >= 2 && divisor == ((divisor>>1)<<1)){
            divisor = divisor>>1;
            dividend = abs(dividend>>1);
        }
        divisorCopy = divisor;
        while(abs(dividend>>1) > abs(divisor>>1)){
            if(divisor<<1 > 0){
                divisor = divisor<<1;
            }else break;
        }
        while(abs(divisor) >= abs(divisorCopy)){
            if(dividend == INT_MIN || abs(dividend) >= abs(divisor)){
                result = (result<<1)|1;
                if(dividend < 0)dividend+=divisor;
                else dividend-=divisor;
            }else{
                result = (result<<1);
            }
            divisor = (divisor>>1);
        }
        return (sign<0)?-result:result;
    }
};

int main(){
    Solution s;
    // //cout<<s.divide(10,3)<<endl;
    cout<<s.divide(-2147483648,2)<<endl;
    int a,b,c,d,e,f;
    // for(int i = 0; i < 100; i++){
    //     a = rand()%100;b = rand()+1;c = (b%2 == 0)?a:-a;d = rand()%100;e = rand()+1;f = (e%2 == 0)?d:-d;
    //     if(f != 0){    
    //         if(s.divide(c,f) != c/f){
    //             cout<<"Bład dla: "<<c <<" "<<f<<endl;
    //         }
    //     }
    //     if(c != 0){
    //         if(s.divide(f,c) != f/c){
    //             cout<<"Bład dla: "<<f <<" "<<c<<endl;
    //         }
    //     }
    // }2147483647

    // for(int i = 0; i < 100; i++){
    //     a = rand();
    //     b = rand()+1;
    //     c = (b%2 == 0)?a:-a;
    //     d = rand();
    //     e = rand()+1;
    //     f = (e%2 == 0)?d:-d;
    //     if(s.divide(c,f) != c/f){
    //         cout<<"Bład dla: "<<c <<" "<<f<<endl;
    //     }
    //     if(s.divide(f,c) != f/c){
    //         cout<<"Bład dla: "<<f <<" "<<c<<endl;
    //     }
    // }
}
