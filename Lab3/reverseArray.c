#include "array_operations.h"

/* Variable declarations */
int i, j;

/**
 * Function Name: reverseArray
 * Purpose: Reverse the elements in a 2D array.
 * Function in parameters: 2D array (arr), number of rows (row), number of columns (column)
 * Function out parameters: None (void)
 * Version: 1
 * Author: Vicente Mba Engung
 */
void reverseArray(int **arr, int row, int column)
{
    int temp; /* Temporary variable to hold an element during swapping */

    /* Reverse rows: Swap the first row with the last, the second with the second to last, and so on. */
    for (i = 0; i < row / 2; i++)
    {
        for (j = 0; j < column; j++)
        {
            temp = arr[i][j];
            arr[i][j] = arr[row - i - 1][j];
            arr[row - i - 1][j] = temp;
        }
    }

    /* Reverse columns: Swap the first column with the last, the second with the second to last, and so on. */
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column / 2; j++)
        {
            temp = arr[i][j];
            arr[i][j] = arr[i][column - j - 1];
            arr[i][column - j - 1] = temp;
        }
    }
}
