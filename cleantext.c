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
float *read_data(int *rows, int *cols) {
    scanf("%d %d", rows, cols);
    printf("The rows: %d ", *rows);
    printf("The cols: %d \n", *cols);

    // allocating memory as a 1d array
    float (*arr)= malloc(*rows * (*cols) * sizeof(float));
    if (arr == NULL) {
        fprintf(stderr, "memory allocation failed for outer arr \n");
        return NULL;
    }

    // reading the text file
    for(int i = 0; i < *rows; i ++) {
        for (int j = 0; j < *cols; j ++) {
            if(scanf("%f", &arr[i * (*cols) + j]) != 1) {
                arr[i * (*cols) + j] = NAN;
            }
        }
    }
    printf("done making array \n");

    return arr;
}

// Description: implementing the deletion method if -d used
float *clean_delete(float *old_data, int *rows, int *cols) {
    int new_rows = 0;

    // counting the number of valid rows
    for (int i = 0; i < *rows; i ++) {
        int delete = 0;
        for (int j = 0; j < *cols; j ++) {
            if(isnan(old_data[i * (*cols) + j]) ) {
                delete = 1;
                break;
            }
        }
        if (delete == 0) {          // if no nan, keep the row
            new_rows ++;
        }
    }

    if (new_rows == 0) {
        *rows = 0;
        return NULL;
    }

    // reallocating memory for each row through new array
    float *new_data = realloc(old_data, new_rows * (*cols) * sizeof(float));
    if (new_data == NULL) {
        fprintf(stderr, "memory allocation failed for outer arr \n");
        return NULL;
    }

    // copying the old_data valid rows to the new_data rows
    int count = 0;
    for(int i = 0; i < *rows; i ++) {
        int delete = 0;
        for (int j = 0; j < *cols; j ++) {
            if (isnan(old_data[i * (*cols) + j])) {
                delete = 1;
                break;
            }
        }
        if (delete == 0) {                              // copying the entire row if valid
            for (int j = 0; j < *cols; j ++) {
                new_data[count * (*cols) + j] = old_data[i * (*cols) + j];
            }
            count ++;
        }
    }
    *rows = new_rows;
    return new_data;
}

// Description: uses the imputation method for replacing the nans with a nan or the average of the column
void clean_impute(float *old_data, int *rows, int *cols) {
    float avg = 0.0;
    float sum = 0.0;

    // casting float * to float (*)[C] to iterate through easily
    float (*arr2d)[*cols] = (float (*)[*cols]) old_data;

    // checking if the entire row is nan
    int curr_col = 0;
    while (curr_col < *cols) {
        int count = 0;
        sum = 0.0;
        for (int i = 0; i < *rows; i ++) {
            if(isnan(arr2d[i][curr_col])) {
                count ++;
                printf("nan in %d %d\n", i, curr_col);
            }
            else {
                sum += arr2d[i][curr_col];          // add the sum of the column which isn't nan
            }
        }
        // calculate the average of the column if at least one nan is there
        if (count > 0) {
            if (count == *rows) {
                avg == 0;
            }
            else {
                printf("sum: %f\n", sum);
                avg = sum / (*rows - count);
            }
            for (int i = 0; i < *rows; i ++) {
                if(isnan(arr2d[i][curr_col])) {
                    arr2d[i][curr_col] = avg;
                }
            }
        }
        curr_col ++;
    }
}

// Description: function that outputs a 2d array in the same set up as the text file input
void output_data(float *data, int *rows, int *cols) {

    // converting to a 2d array to print 1d array
    printf("%d %d", *rows, *cols);

    float (*arr2d)[*cols] = (float (*)[*cols]) data;

    for(int i = 0; i < *rows; i ++) {
        printf("\n");
        for (int j = 0; j < *cols; j ++) {
            printf("%.3f ", arr2d[i][j]);
        }
    }
} 