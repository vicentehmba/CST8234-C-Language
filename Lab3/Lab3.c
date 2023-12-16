/*****************************************************
 * Student Name: Vicente Mba Engung
 * Student Number: 041029226
 * Assignment Number: Lab 3 - Array Manipulation
 * Course Name and Number: CST8234 - 300
 * Lab Section: 301
 * Professor's Name: Harleen Kaur
 * Due Date of Assignment: October 22, 2023.
 * Submission Date of Assignment: Octuber 13, 2023.
 * List of source and header files in the project: 5
 *****************************************************/

/*****************************************************
 * Filename: Lab3.c
 * Version: 1
 * Author/Student Name: Vicente Mba Engung
 * Student Number: 041029226
 * Course Name and Number: CST8234 - 300
 * Lab Section: 301
 * Assignment Number: 3
 * Assignment Name: Array Manipulation
 * Due Date: October 22, 2023.
 * Submission Date: October 13, 2023.
 * Professor's Name: Harleen Kaur
 * Purpose: Manipulation of 2D Array
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_operations.h"

/**
 * Function Name: main
 * Purpose: The main function that drives the program. It allows the user to perform various operations on a 2D array.
 * Function in parameters: None
 * Function out parameters: Integer (return code)
 * Version: 1
 * Author: Vicente Mba Engung
 */
int main(void)
{
    /* Variables definitions */
    int row = 0;
    int column = 0;
    int **arr;
    int i, j, option;
    int inputCheck;

    while (1) /* While loop to validate input and a square matrix array */
    {
        while (1)
        {
            /* Prompts the user to enter the row for the 2D array */
            printf("Enter the row size of the 2D array:\n");
            if (scanf("%d", &row) == 1 && row > 0)
            {
                break; /* Exit the loop if a valid positive integer is entered */
            }
            else
            {
                printf("\nInvalid input. Enter positive numeric values only.\n\n");
                while (getchar() != '\n')
                {
                    /* Clear the input buffer */
                }
            }
        }

        while (1)
        {
            /* Prompts the user to enter the column for the 2D array */
            printf("\nEnter the column size of the 2D array:\n");
            if (scanf("%d", &column) == 1 && column > 0)
            {
                break; /* Exit the loop if a valid positive integer is entered */
            }
            else
            {
                printf("\nInvalid input. Enter positive numeric values only.\n");
                while (getchar() != '\n')
                {
                    /* Clear the input buffer */
                }
            }
        }
        /* Checks IF rows and columns are equal for a square matrix array*/
        if (row != column)
        {
            printf("\nInvalid row and column entered. Please enter equal sizes for a square 2D array.\n");
            continue; /* Continue to ask for new sizes for rows and columns */
        }
        else
        {
            break; /* Breaks the loop IF rows and columns are equal */
        }
    }

    /* Allocate space dynamically for the 2D array using malloc method */
    arr = (int **)malloc(row * sizeof(int *));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (i = 0; i < row; i++)
    {
        arr[i] = (int *)malloc(column * sizeof(int));
        if (arr[i] == NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }
    }

    while (1)
    {
        int validInput = 1; /* Flag to track valid input */

        /* Prompts the user to enter values for the array */
        printf("\nEnter %d positive integers (space separated):\n", row * column);

        for (i = 0; i < row; i++)
        {
            for (j = 0; j < column; j++)
            {
                if (scanf("%d", &arr[i][j]) != 1 || arr[i][j] <= 0)
                {
                    validInput = 0; /* Set the flag to indicate invalid input */
                    break;          /* Exit the loop if invalid input is detected */
                }
            }
            if (!validInput)
            {
                break; /* Exit the outer loop if invalid input is detected */
            }
        }

        if (validInput)
        {
            break; /* Exit the entire input loop if all inputs are valid */
        }
        else
        {
            printf("\nInvalid input. Enter positive numeric values only.\n");
            while (getchar() != '\n')
            {
                /* Clear the input buffer */
            }
        }
    }

    do
    {
        /* Displays a menu of available options */
        printf("\nChoose an operation: \n");
        printf("(0)  :  exit \n");
        printf("(1)  :  reverse array \n");
        printf("(2)  :  randomize array \n");
        printf("(3)  :  sort array \n");
        printf("(4)  :  print array \n");

        /* Accepts user input and validates it */
        inputCheck = scanf("%d", &option);
        if (inputCheck != 1)
        {
            /* Prints error mesaage if input validation fails */
            printf("Invalid input. Enter a number between 0 and 4.\n");
            while (getchar() != '\n')
                continue;
        }
        /* Check if user input is less than 0 or grater than 4 */
        else if (option < 0 || option > 4)
        {
            /* Prints error mesaage if input validation fails */
            printf("Invalid input. Enter a positive number between 0 and 4.\n");
        }
        else
        {
            /* Switch statement to cicle trouth menu options */
            switch (option)
            {
            case 0:
                /* Exits the program */
                exit(0);
                break;

            case 1:
                /* Calls reverseArray and printArray methods */
                reverseArray(arr, row, column);
                printArray(arr, row, column);
                break;
            case 2:
                /* Calls randomizeArray and printArray methods */
                randomizeArray(arr, row, column);
                printArray(arr, row, column);
                break;

            case 3:
                /* Calls sortArray and printArray methods */
                sortArray(arr, row, column);
                printArray(arr, row, column);
                break;

            case 4:
                /* Calls printArray methods */
                printArray(arr, row, column);
                break;

            default:
                /* Prints error message if input validation fails */
                printf("Invalid input. Enter a number between 0 and 4.\n");
                break;
            }
        }
    } while (option != 0);

    for (i = 0; i < row; i++)
    {
        /* Free the memory for individual rows within the 2D array */
        free(arr[i]);
    }
    /* Free the memory for the array of row pointers */
    free(arr);

    return EXIT_SUCCESS;
}
