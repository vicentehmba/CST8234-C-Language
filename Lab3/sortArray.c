#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_operations.h"

/* Variable declarations */
int i, j;

/**
 * Function Name: compare
 * Purpose: Compare two integers for use in sorting.
 * Function in parameters: Pointers to two integer values (a and b).
 * Function out parameters: An integer value (-1, 0, or 1) indicating the comparison result.
 * Version: 1
 * Author: Vicente Mba Engung
 */
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

/**
 * Function Name: sortArray
 * Purpose: Sort the elements in a 2D array in ascending order.
 * Function in parameters: 2D array (arr), number of rows (row), number of columns (column)
 * Function out parameters: None (void)
 * Version: 1
 * Author: Vicente Mba Engung
 */
void sortArray(int **arr, int row, int column)
{
    /* Sort each row of the 2D array individually */
    for (i = 0; i < row; i++)
    {
        qsort(arr[i], column, sizeof(int), compare);
    }
}
