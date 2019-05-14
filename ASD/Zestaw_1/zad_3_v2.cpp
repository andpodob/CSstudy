#include <bits/stdc++.h>

using namespace std;
const int MAX_H = 100;

struct box{
    int c_x, c_y, f_x, f_y;
    box(int ceil_x, int ceil_y, int floor_x, int floor_y){
        c_x = ceil_x;
        c_y = ceil_y;
        f_x = floor_x;
        f_y = floor_y;
    }
};

int check(int A, box* tab[], int n){
    int i;
    int c_y, f_y, width;
    int t[MAX_H][2];
    for(i = 0; i < MAX_H; i++){
        t[i][0] = 0;
        t[i][1] = 0;
    }
    for(i = 0; i < n; i++){
        c_y = tab[i]->c_y;
        f_y = tab[i]->f_y;
        width = tab[i]->f_x - tab[i]->c_x;
        t[c_y][1]++;
        for(int j = f_y; j < c_y; j++){
            t[j][0]+=width;
        }
    }
    for(i = 1; i < MAX_H; i++){
        t[i][0] += t[i-1][0];
        t[i][1] += t[i-1][1];
    }
    i = 0;
    while(t[i][0] <= A && i < MAX_H-1)i++;
    return t[i][1];
}

int main(){
    box* b1 = new box(0,1,2,0);
    box* b2 = new box(3,3,4,0);
    box* b3 = new box(1,4,5,2);

    box* tab[3] = {b1,b2,b3};

    cout<<check(14,tab,3)<<endl;
}