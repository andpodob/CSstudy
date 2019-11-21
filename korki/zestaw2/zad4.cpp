#include <bits/stdc++.h>

using namespace std;

bool checkNumber(int n){
    while (n%5 == 0)
    {
        n /= 5;
    }
    while (n%3 == 0)
    {
        n /= 3;
    }
    while (n%2 == 0)
    {
        n /= 2;
    }

    if(n == 1){
        return true;
    }
    return false;
}

int main(){

}