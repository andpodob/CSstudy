#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string map[30] = {"I","II","III","IV","V","VI","VII","VIII","IX",
                          "X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
                          "C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
                          "M","MM","MMM"};
        string result = "";
        int numberOfDigits = log10(num)+1;
        int digit = 0;
        for(int i = numberOfDigits; i > 0; i--){
            switch(i){
                case 4:
                    digit = num/1000;
                    if(digit > 0)result+=map[digit+26];
                    break;
                case 3:
                    digit = num/100;
                    if(digit > 0)result+=map[digit+17];
                    break;
                case 2:
                    digit = num/10;
                    if(digit > 0)result+=map[digit+8];
                    break;
                case 1:
                    digit = num/1;
                    if(digit > 0)result+=map[digit-1];
                    break;
            }
            num-=digit*pow(10,i-1);
        }
        return result;
    }
};

int main(){
    Solution s;
    cout<<s.intToRoman(1994)<<endl;
}