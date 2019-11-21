#include <bits/stdc++.h>

using namespace std;

const int MAX = 3;

bool checkNumber(int a){
    do{
        int d = a%10;
        a = a/10;
        if(d%2 == 0) return false;
    }while(a > 0);
    return true;
}

bool checkTable(int t[MAX][MAX]){
    bool numberFound = true;
    //dla kazdego wiersza
    for(int i = 0; i < MAX && numberFound; i++){
        numberFound = false;
        //dla kazdej komórki w wierszu
        for(int j = 0; j < MAX && !numberFound; j++){
            numberFound = checkNumber(t[i][j]);
        }
    }
    return numberFound;
}

int main(){
    //test checkNumber
    cout<<"0: "<<checkNumber(0)<<endl;
    cout<<"1: "<<checkNumber(1)<<endl;
    cout<<"13: "<<checkNumber(13)<<endl;
    cout<<"14: "<<checkNumber(14)<<endl;
    cout<<"35798: "<<checkNumber(35798)<<endl;
    cout<<"3579: "<<checkNumber(3579)<<endl;

    //test checkTable
    int t[3][3] = {{2,2,2},{0,1,0},{4,1,4}};
    cout<<checkTable(t)<<endl;
    int t2[3][3] = {{2,5,2},{0,1,0},{4,1,4}};
    cout<<checkTable(t2)<<endl;
}