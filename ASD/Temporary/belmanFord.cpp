#include <bits/stdc++.h>
using namespace std;
#define INF 1000

/*
    Hej, 
    przepisałem ten algorytm z kartki, myślę że cenną obserwacją jest fakt że mój algrytm nie traktuje liczb
    w tablicy C jako wag krawędzi, pola tablicy są traktowane jako wieżchołki grafu, a liczby w polach tablicy
    jako już wyliczona najkrótsza odległość do danego pola. Mam jedynie wątpliwość czy stała A może pozostać równa 1,
    na moich dwóch testach z "meandrami" zadziałało, być może da się tak zaprojektować testy aby ten algorytm się wysypał.

    Z góry dziękuję za chęci i poświęcony czas na czytanie tych wypocin ;)
 */

const int A = 1;

int min4(int a, int b, int c, int d){
    return min(min(a,b),min(c,d));
}

int highway(int** C, int n){
    int dp[n][n];
    int a, b, c, d;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = C[0][0];
    for(int k = 0; A*k < n; k++){ 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                a= b = c = d = INF;
                if(i > 0) a = dp[i-1][j];
                if(i < n-1) b = dp[i+1][j];
                if(j > 0) c = dp[i][j-1];
                if(j < n-1) d = dp[i][j+1];
                a = min4(a,b,c,d);
                if(a + C[i][j] < dp[i][j]){
                    dp[i][j] = a + C[i][j];
                }
            }
        }
    }
    return dp[n-1][n-1];
}

int main(){
    int test1[5][5]={
        {1,1,1,1,1},
        {100,100,100,100,1},
        {1,1,1,1,1},
        {1,100,100,100,100},
        {1,1,1,1,1}
    };

     int test2[5][5]={
        {1,5,5,5,5},
        {1,5,5,5,5},
        {1,5,1,1,1},
        {1,1,1,5,1},
        {5,5,5,5,1}
    };

    int **C = new int*[5]; 
    for(int i = 0; i < 5;i++){
        C[i] = new int[5];
        for(int j = 0; j < 5; j++){
            // C[i][j] = test1[i][j]; //test1 odkomentowac/zakomentowac
            C[i][j] = test2[i][j]; //test2 odkomentowac/zakomentowac
        }
    }

    cout<<highway(C,5)<<endl;
}