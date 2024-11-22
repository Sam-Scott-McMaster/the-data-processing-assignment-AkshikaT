#include <stdio.h>
#include <stdlib.h>

// Description: when the --help is used
void help();

// Description: when there is an error in the command line inputs
int usage();

// Description: to read the number of rows and cols and then the put the text file into 2d array
float *read_data(int *rows, int *cols);

// Description: using the delete method
float *clean_delete(float *old_data, int *rows, int *cols);

// Description: using the imputation method
void clean_impute(float *old_data, int *rows, int *cols);

// Description: outputting the array
void output_data(float *data, int *rows, int *cols);