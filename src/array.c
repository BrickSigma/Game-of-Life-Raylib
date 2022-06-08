#include "../headers/array.h"

int** createArray(int h, int w) {
    int* values = calloc(h*w, sizeof(int));
    int** rows = malloc(h*sizeof(int*));
    for (int i=0; i<h; ++i)
    {
        rows[i] = values + i*w;
    }
    return rows;
}

void destroyArray(int** arr) {
    free(*arr);
    free(arr);
}

void fillArray(int **arr, int h, int w, int val) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            arr[i][j] = val;
        }
    }
}

int sumArray(int **arr, int h, int w, Range range) {
    int sum = 0;
    for (int i = range.y; i < range.y + range.height; i++) {
        if (i < 0 || i >= h) {continue;}
        for (int j = range.x; j < range.x + range.width; j++) {
            if (j < 0 || j >= w) {continue;}
            sum += arr[i][j];
        }
    }
    return sum;
}


void copyArray(int **dst, int **src, int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            dst[i][j] = src[i][j];
        }
    }
}