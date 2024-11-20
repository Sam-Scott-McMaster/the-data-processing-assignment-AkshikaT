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

// Description: creates a rectangular array of floats which is filled from the standard input
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

// Description: implementing the deletion method if -d used
float **clean_delete(float **old_data, int *rows, int *cols) {
    int new_rows = 0;

    // iterating through old array to find the number of rows for new array
    for (int i = 0; i < *rows; i ++) {
        int delete = 0;
        for (int j = 0; j < *cols; j ++) {
            if(isnan(old_data[i][j]) ) {
                delete = 1;
                break;
            }
        }
        if (delete == 0) {          // if no nan
            new_rows ++;
        }
    }

    // allocating memory for each row
    float **new_data = malloc(new_rows * sizeof(float *));
    if (new_data == NULL) {
        fprintf(stderr, "memory allocation failed for outer arr \n");
        return NULL;
    }
    for (int i = 0; i < new_rows; i ++) {
        new_data[i] = malloc(*cols * sizeof(float));
        if (new_data[i] == NULL) {
            fprintf(stderr, "memory allocation failed\n");
            return NULL;
        }
    }

    // copying the old valid rows to the new array
    int count = 0;                          // row count for new_data
    for(int i = 0; i < *rows; i ++) {
        int delete = 0;
        for(int j = 0; j < *cols; j ++) {
            if(isnan(old_data[i][j]) ) {
                delete = 1;
                break;
            }
        }
        if(delete == 0) {                   // copying valid rows to new_data
            new_data[count] = old_data[i];
            count ++;
        }
    }
    *rows = new_rows;
    return new_data;
}

// Description: function that outputs a 2d array in the same set up as the text file input
void **output_data(float **data, int *rows, int *cols) {
    printf("%d %d", *rows, *cols);
    for(int i = 0; i < *rows; i ++) {
        printf("\n");
        for (int j = 0; j < *cols; j ++) {
            printf("%.3f ", data[i][j]);
        }
    }
} 