/*****************************************************
 * Student Name: Vicente Mba Engung
 * Student Number: 041029226
 * Assignment Number: Lab 2 - Array Manipulation
 * Course Name and Number: CST8234 - 300
 * Lab Section: 301
 * Professor's Name: Harleen Kaur
 * Due Date of Assignment: October 8, 2023.
 * Submission Date of Assignment: Octuber 8, 2023.
 * List of source and header files in the project: 3
 *****************************************************/

/*****************************************************
 * Filename: manipulator.c
 * Version: 1
 * Author/Student Name: Vicente Mba Engung
 * Student Number: 041029226
 * Course Name and Number: CST8234 - 300
 * Lab Section: 301
 * Assignment Number: 2
 * Assignment Name: Array Manipulation
 * Due Date: October 8, 2023.
 * Submission Date: October 8, 2023.
 * Professor's Name: Harleen Kaur
 * Purpose: Manipulation of array
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to reverse an array */
void reverseArray(int arr[], int length)
{
    int start = 0;
    int end = length - 1;

    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

/* Function to randomize an array using Fisher-Yates shuffle */
void randomizeArray(int arr[], int length)
{
    int i;

    srand(time(NULL));
    for (i = length - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/* Comparison function for qsort */
int compareIntegers(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(void)
{

    int arrLength;
    int *arr;
    int i;
    int option = 0;

    /* Prompt the user for the array size */
    printf("Enter the length: \n");
    scanf("%d", &arrLength);

    /* Dynamically allocate memory for the array */
    arr = (int *)malloc(arrLength * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
    }

    printf("Enter %d numbers (space separated): \n", arrLength);

    /* Adding values dynamically into the array */
    for (i = 0; i < arrLength; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {
        /* Displays menu options */
        printf("Choose an operation: \n");
        printf("(0)  :  exit \n");
        printf("(1)  :  reverse array \n");
        printf("(2)  :  randomize array \n");
        printf("(3)  :  sort array \n");

        /* Accepts user input */
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            exit(0);
            break;

        case 1:
            /* Method to reverse the array */
            reverseArray(arr, arrLength);
            printf("{ ");
            for (i = 0; i < arrLength; i++)
            {
                printf("%d ", arr[i]);
            }
            printf(" }");
            break;

        case 2:
            /* Method to randomize the array */
            randomizeArray(arr, arrLength);
            printf("{ ");
            for (i = 0; i < arrLength; i++)
            {
                printf("%d ", arr[i]);
            }
            printf(" }");
            break;

        case 3:
            /* Sort the array using the qsort function */
            qsort(arr, arrLength, sizeof(int), compareIntegers);
            printf("{ ");
            for (i = 0; i < arrLength; i++)
            {
                printf("%d ", arr[i]);
            }
            printf(" }");
            break;

        default:
            printf("Invalid option. Please, try again. \n");
            break;
        }
        printf("\n\n");
    } while (option != 0);

    /* Free the dynamically allocated memory */
    free(arr);
    return 0;
}
