/************************************
 * Student Name: Vicente Mba Engung
 *
 ************************************/

/************************************
 * File Name: amicableNos.c
 * Version: 1
 * Student Number: 041029226
 * Assignment Number: Lab 1
 * Course Name and Number: 301
 * Professor Name: Natalie Gluzman
 * Due Date: September 20, 2023
 * Submission Date:
 * Purpose: Check if two numbers are friendly pairs
 * List of sources: N/A
 ************************************/

#include <stdio.h>
#include <stdlib.h>

/* Program #1 */
/* Function to check amicable numbers */
int amicableNos(int num1, int num2)
{
    int sum1 = 0;
    int sum2 = 0;
    int i;

    /* Adding factors of the first number (num1) */
    for (i = 1; i <= num1 / 2; i++)
    {
        /* Add IF 'i' is a factor */
        if (num1 % i == 0)
        {
            sum1 += i;
        }
    }
    /* Adding factors of the second number (num2) */
    for (i = 1; i <= num2 / 2; i++)
    {
        /* Add IF 'i' is a factor */
        if (num2 % i == 0)
        {
            sum2 += i;
        }
    }

    /* Checking IF the numbers are amicable */
    if ((num1 == sum2) && (num2 == sum1))
    {
        printf("Entered nos. are amicable.\n");
    }
    else
    {
        printf("Entered nos. are not amicable. Try agin\n");
    }

    return EXIT_SUCCESS;
}

int main(void)
{
    int num1;
    int num2;

    /* Taking number inputs */
    printf("Enter the two nos: ");
    scanf("%d %d", &num1, &num2);

    /* Calling the function */
    amicableNos(num1, num2);

    return EXIT_SUCCESS;
}
