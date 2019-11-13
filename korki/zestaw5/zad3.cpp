#include <bits/stdc++.h>

using namespace std;

const int SIZE = 100;

struct hetman{
    int w;
    int k;
};

struct dane{
    hetman t[100];
    int N;
};

bool checkRow(bool plansza[SIZE][SIZE], int k){
    bool flag = false;
    for(int i = 0; i < SIZE; i++){
        if(plansza[i][k]){
            if(flag) return true;
            flag = true;
        }
    }
    return false;
}

bool checkColumn(bool plansza[SIZE][SIZE], int k){
    bool flag = false;
    for(int i = 0; i < SIZE; i++){
        if(plansza[k][i]){
            if(flag) return true;
            flag = true;
        }
    }
    return false;
}

bool checkDiagonal(bool plansza[SIZE][SIZE], int k){
    int x1, y1;
    int x2, y2;
    bool flag1 = false;
    bool flag2 = false;

    x1 = k; y1 = 0;
    x2 = SIZE-k-1; y2 = SIZE-1;

    while (x1 >= 0)
    {
        if((x1 != x2 || y1 != y2) && plansza[x1][y1] && plansza[x2][y2]) return true;
        if(plansza[x1][y1]){
            if(flag1) return true;
            flag1 = true;
        }
        if(plansza[x2][y2]){
            if(flag2) return true;
            flag2 = true;
        }
        x1--; y1++;
        x2--; y2++;
    }
    return false;
}

//jezeli dwa się przecianają to zwracamy true, jezeli zadne dwa sie nie przecinaja zwracamy flase
bool check(dane d){
    bool plansza[SIZE][SIZE];
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            plansza[i][j] = false;
        }
    }
    int x, y;
    for(int i = 0; i < d.N; i++){
        x = d.t[i].k;
        y = d.t[i].w;
        plansza[x][y] = true;
    }

    for(int i = 0; i < SIZE; i++){
        if(checkColumn(plansza, i)) return true;
        if(checkRow(plansza, i)) return true;
        if(checkDiagonal(plansza, i)) return true;
    }
    return false;
}

int main(){

}