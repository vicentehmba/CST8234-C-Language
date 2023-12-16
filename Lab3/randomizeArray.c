#include <time.h>
#include <stdlib.h>
#include "array_operations.h"

/* Variable declarations */
int i, j;

/**
 * Function Name: randomizeArray
 * Purpose: Shuffle the elements in a 2D array in a random order.
 * Function in parameters: 2D array (arr), number of rows (row), number of columns (column)
 * Function out parameters: None (void)
 * Version: 1
 * Author: Vicente Mba Engung
 */
void randomizeArray(int **arr, int row, int column)
{
    /* Calculate the total number of elements in the 2D array */
    int totalElements = row * column;

    /* Dynamically allocate memory for a 1D array to temporarily store the elements */
    int *elements = (int *)malloc(totalElements * sizeof(int));

    /* Copy elements from the 2D array to the 1D array */
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            elements[i * column + j] = arr[i][j];
        }
    }

    /* Shuffle the elements using the Fisher-Yates shuffle algorithm */
    for (i = totalElements - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }

    /* Copy the shuffled elements back into the original 2D array */
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            arr[i][j] = elements[i * column + j];
        }
    }

    /* Free the dynamically allocated memory for the 1D array */
    free(elements);
}
