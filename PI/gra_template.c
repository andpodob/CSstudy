#include<stdio.h>
#include <stdlib.h>

int count_routes(int** board, int N, int from_x, int from_y, int to_x, int to_y) {
    if(board[to_x][to_y] == 0) return 0;
    board[to_x][to_y] = -1;
    for(int y = to_y; y >= from_y; y--){
        for(int x = to_x; x >= from_x; x--){
            if(x == to_x && y == to_y)continue;
            if(board[x][y] == 1){
                board[x][y] = 0;
                if(x+1 < N)board[x][y]+=board[x+1][y];
                if(y+1 < N)board[x][y]+=board[x][y+1];
                if(x+1 < N && y+1 < N)board[x][y]+=board[x+1][y+1];
            }
        }
    }
    return (-1)*board[from_x][from_y];
}

int main() {
    int N;
    scanf("%d", &N);
    int** board = malloc(N*sizeof(int*));
    for (int i=0; i<N; i++) {
        board[i] = malloc(N*sizeof(int));
        for (int j=0; j<N; j++) scanf("%d", &board[i][j]);
    }

    int from_x, from_y, to_x, to_y;
    scanf("%d", &from_x);
    scanf("%d", &from_y);
    scanf("%d", &to_x);
    scanf("%d", &to_y);
    printf("%d\n", count_routes(board, N, from_x, from_y, to_x, to_y));

    for(int i=0; i<N; i++) free(board[i]);
    free(board);
}