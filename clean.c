#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clean.h"

/*
The Data Processing Assignment
Name: Akshika Thiyagendran
Date: November 17, 2024
Description: Main function that makes all the necessary function calls
*/

int main(int argc, char *argv[]) {
    int ifDelete = 0;                   // if 1, then use deletion strategy. else, imputation strategy
    
    int rows = 0;
    int cols = 0;
    if (argc == 2 && strcmp(argv[1], "-d") == 0) {
        ifDelete = 1;
    }
    else if (argc == 2 && strcmp(argv[1], "--help") == 0) {
        help();
        return EXIT_SUCCESS;
    }
    else if (argc != 1) {           // if one argument, the imputation method
        usage();
        return EXIT_FAILURE;
    }

    // read the data from the user
    float *data = read_data(&rows, &cols);

    // if the -d used, then the deletion strategy is implemented
    if (ifDelete == 1) {
        data = clean_delete(data, &rows, &cols);
        float (*data2d)[cols] = (float (*)[cols]) data;
        output_data(data, &rows, &cols);
    }
    else {
        clean_impute(data, &rows, &cols);
        output_data(data, &rows, &cols);
    }
    return EXIT_SUCCESS;
}