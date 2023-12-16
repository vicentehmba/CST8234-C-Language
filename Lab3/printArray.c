#include <stdio.h>
#include "array_operations.h"

/* Variable declarations */
int i, j;

/**
 * Function Name: printArray
 * Purpose: Print the elements of a 2D array to the console.
 * Function in parameters: 2D array (arr), number of rows (row), number of columns (column)
 * Function out parameters: None (void)
 * Version: 1
 * Author: Vicente Mba Engung
 */
void printArray(int **arr, int row, int column)
{
    /* Loop through the rows of the 2D array */
    for (i = 0; i < row; i++)
    {
        /* Loop through the columns of the 2D array */
        for (j = 0; j < column; j++)
        {
            /* Print the element at the current row and column */
            printf("%d ", arr[i][j]);
        }

        /* Move to the next line to start a new row */
        printf("\n");
    }
}
