#include <bits/stdc++.h>

using namespace std;

int lastNonZeroDigit(int N){
    int result = 1;
    int counter = 0;
    int temp_N;
    for(; N >= 1; N--){
        temp_N = N;
        while (temp_N%5 == 0)
        {
            temp_N /=5;
            counter++;
        }
        while (temp_N%2 == 0 and counter > 0){
            temp_N /= 2;
            counter--; 
        }

        result *= temp_N;
        while (result%10 == 0)
        {
            result/=10;
        }
        result = result%10;
    }
    return result;
}

int main(){
    cout<<lastNonZeroDigit(5)<<endl;
    cout<<lastNonZeroDigit(6)<<endl;
    cout<<lastNonZeroDigit(10)<<endl;
    cout<<lastNonZeroDigit(100)<<endl;
    cout<<lastNonZeroDigit(150)<<endl;
    cout<<lastNonZeroDigit(89)<<endl;
}