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
float **read_data(int *rows, int *cols) {
    scanf("%d %d", rows, cols);
    printf("The rows: %d ", *rows);
    printf("The cols: %d \n", *cols);
    float **arr = malloc(*rows * sizeof(float *));
    if (arr == NULL) {
        fprintf(stderr, "memory allocation failed for outer arr \n");
        return NULL;
    }

    for (int i = 0; i < *rows; i ++) {
        arr[i] = malloc(*cols * sizeof(float));
        if (arr[i] == NULL) {
            fprintf(stderr, "memory allocation failed\n");
            return NULL;
        }
    }

    // reading the text file
    for(int i = 0; i < *rows; i ++) {
        for (int j = 0; j < *cols; j ++) {
            if(scanf("%f", &arr[i][j]) != 1) {             // if input not float, store as NAN
                arr[i][j] = NAN;
            }
        }
    }
    printf("done making array \n");

    return arr;
}

// implementing the deletion method if -d used
// float *clean_delete(float *old_data, int *rows, int *cols) {

//     // ensuring the every row with a nan is removed in the new data array
//     float *new_data = malloc(*rows * *cols * sizeof(float));
//     for(int i = 0; i < *rows; i ++) {
//         int delete = 0;                         // will be 1 if the row has a NAN
//         int curr_col = 0;
//         for (int j = 0; j < *cols; j ++) {
//             if (old_data[i * *cols + j] == NAN) {
//                 delete = 1;
//             }
//             curr_col = j;
//         }
//         // copying row by row from old_data to new_data if no NAN
//         if (delete == 0) {
//             new_data[i] = old_data[i * *cols + curr_col];
//         }
//     }
// }

void **output_data(float **data, int *rows, int *cols) {
    printf("%d %d", *rows, *cols);
    for(int i = 0; i < *rows; i ++) {
        printf("\n");
        for (int j = 0; j < *cols; j ++) {
            printf("%.3f ", data[i][j]);
        }
    }
} 