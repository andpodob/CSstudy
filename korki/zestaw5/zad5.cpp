#include <bits/stdc++.h>

using namespace std;

const int MAX = 32;

struct punkt{
    int x;
    int y;
};

struct dane{
    punkt t[100];
    int N;
};


bool checkSquare(bool t[MAX][MAX], punkt p, int size){
    int pocz_x = p.x;
    int pocz_y = p.y;
    for(int y = pocz_y; y < pocz_y+size; y++ ){
        for(int x = pocz_x; x < pocz_x+size; x++){
            if(t[x][y] == true){
                if(!((x==pocz_x and y==pocz_y) or (x==pocz_x+size-1 and y==pocz_y) or (x==pocz_x and y==pocz_y+size-1) or (x==pocz_x+size-1 and y==pocz_y+size-1))){
                    return false;
                }
            }
        }
    }
    return true;
}

bool squareFound(dane d){
    //będziemy iterować po kolejnych wielkościach kwadratu od 2..32
    bool t[MAX][MAX];
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            t[i][j] = false;
        }
    }
    for(int i = 0; i < d.N; i++){
        t[d.t[i].x][d.t[i].y] = true;
    }
}