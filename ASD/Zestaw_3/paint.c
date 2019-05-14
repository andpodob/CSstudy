#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct point {
    int x, y;
} point;

typedef struct queue {
    int start, end, size;
    point **elements;
} queue;

/****************************
* implement functions below *
****************************/

queue *new_queue(int size) {
    queue *q = malloc(size*sizeof(queue));
    q->start = 0;
    q->end = 0;
    q->size = size;
    return q;
}

void delete_queue(queue *q) {
    free(q->elements);
    free(q);
}

void put(queue *q, point *value) {
    if(1+q->end == q->size) return -1;

    q->elements[++(q->end)] = value;
    if(1+q->end == q->size){
        int i = q->start;
        int delta = q->start;
        while(i <= q->end){
            q->elements[i-delta] = q->elements[i];
            i++;
        }
        q->end = q->end - delta;
        q->start = 0;
    }
}

point *get(queue *q) {
    point *p = q->elements[q->start];
    q->start = q->start++;
    if(q->start-1 == q->end) q->start = q->end = 0;
    return p;
}



bool is_empty(queue *q) {
    
}

void fill(int **image, int n, int x, int y, int color) {
    queue *points = new_queue(n * n);
    // put first point
    while (!is_empty(points)) {
        // add your code here
    }
    delete_queue(points);
}

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    int **image = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        image[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    int x, y, color;
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        scanf("%d", &y);
        scanf("%d", &color);
        fill(image, n, x, y, color);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
        free(image[i]);
    }
    free(image);
}