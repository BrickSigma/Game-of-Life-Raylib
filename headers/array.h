#ifndef _STDLIB_H
#include <stdlib.h>
#endif

/**
 * A Range object used for looping through sections of an array
 * {y, x, height, width} 
 */
typedef struct Range{
    int y;
    int x;
    int height;
    int width;
} Range;

/**
 *  Create a 2D array filled with zeros 
 */
int **createArray(int h, int w);

/**
 * Free array memory
 */
void destroyArray(int **arr);

/**
 * Fill an array with a specified value
 */
void fillArray(int **arr, int h, int w, int val);

/**
 * Sum up the elements of an array between a range 
 */
int sumArray(int **arr, int h, int w, Range range);

/**
 * Copy the elements of one array to another
 */
void copyArray(int **dst, int **src, int h, int w);