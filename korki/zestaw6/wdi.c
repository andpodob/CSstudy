#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <zconf.h>

int N = 3;

void move(int t1[N][N], int t2[N*N]) {
    int indices[N];
    for (int i = 0; i < N; ++i) {
        indices[i] = 0;
    }
    for (int j = 0; j < N * N; ++j) {
        int min_tab = 0;
        int smallest = INT_MAX;
        for (int i = 0; i < N; ++i) {
            if (indices[i]<N && t1[i][indices[i]] < smallest) {
                min_tab = i;
                smallest = t1[i][indices[i]];
            }
        }
        indices[min_tab]++;
        t2[j] = smallest;
    }
}

int main() {
    int t1[N][N];
    t1[0][0]=0;
    t1[0][1]=2;
    t1[0][2]=3;

    t1[1][0]=1;
    t1[1][1]=1;
    t1[1][2]=3;

    t1[2][0]=1;
    t1[2][1]=5;
    t1[2][2]=8;
    int t2[N * N];
    move(t1, t2);
    for (int i = 0; i < N * N; ++i) {
        printf("%d ", t2[i]);
    }
    return 0;
}