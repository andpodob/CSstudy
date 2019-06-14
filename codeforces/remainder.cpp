#include <bits/stdc++.h>

using namespace std;

int reminder(int x, int y, string number, int n){
    int operation_counter = 0;
    for(int i = 0; i < y; i++){
        if(number[n-i-1] == '1'){
            operation_counter++;
        }
    }
    if(number[n-y-1] == '0'){
        operation_counter++;
    }
    for(int i = y+1; i < x; i++){
        if(number[n-i-1] == '1'){
            operation_counter++;
        }
    }
    return operation_counter;
}

int main(){
    int n, x, y;
    cin>>n;cin>>x;cin>>y;
    string number;
    cin>>number;
    cout<<reminder(x,y,number,n)<<endl;
}