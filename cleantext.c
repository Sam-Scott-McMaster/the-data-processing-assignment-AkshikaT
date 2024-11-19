#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "clean.h"


/*
The data processing assignment
Name: Akshika Thiyagendran
Date: November 17, 2024
Description: contains all the methods to clean and handle arguments for cleaning text utility
*/

// creates a rectangular array of floats which is filled from the standard input
float *read_data(int *rows, int *cols) {
    scanf("%d %d", rows, cols);
    printf("The rows: %d ", *rows);
    printf("The cols: %d \n", *cols);

    // allocating memory for a 2d array
    float *arr =  malloc(*rows * (*cols) * sizeof(float));
    if (arr == NULL) {
        fprintf(stderr, "memory allocation failed\n");
    }
    printf("done allocating memory \n");

    // reading the text file
    for(int i = 0; i < *rows; i ++) {
        for (int j = 0; j < *cols; j ++) {
            if(scanf("%f", &arr[i * *cols + j]) != 1) {             // if input not float, store as NAN
                arr[i * *cols + j] = NAN;
            }    
        }
    }
    printf("done making array \n");

    return arr;
}