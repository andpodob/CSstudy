#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int N = 8;
int M = 8;

bool move(int x, int y, bool visited[N][M]){
    visited[x][y] = true;
    int a[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int b[] = {1, 2, 2, 1, -1, -2, -2, -1};
    bool entered = false;
    for (int i = 0; i < 8; ++i) {
        if (0 <= x + a[i] && x + a[i] < N && 0 <= y + b[i] && y + b[i] < N) {
            if (!visited[x + a[i]][y + b[i]]) {
                entered = true;
                if(move(x + a[i], y + b[i], visited)) {
                    return true;
                }
            }
        }
    }
    bool all_fields_visited = true;
    if (!entered) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (!visited[i][j]) {
                    all_fields_visited = false;
                    break;
                }
            }
        }
    }
    visited[x][y] = false;
    return all_fields_visited;
}

int main() {
    bool visited[N][M];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            visited[i][j] = false;
        }
    }
    printf(move(0, 0, visited) ? "true" : "false");
    return 0;
}