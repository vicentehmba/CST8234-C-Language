/************************************
 * Student Name: Vicente Mba Engung
 *
 ************************************/

/************************************
 * File Name: checkzeros.c
 * Version: 1
 * Student Number: 041029226
 * Assignment Number: Lab 1
 * Course Name and Number: 301
 * Professor Name: Natalie Gluzman
 * Due Date: September 20, 2023
 * Submission Date:
 * Purpose: Program to check if a number has 3 consecutive zeros
 * List of sources: N/A
 ************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool hasThreeConsecutiveZeros(int number)
{
    int consecutiveZeros = 0;

    while (number != 0)
    {
        if (number % 10 == 0)
        {
            consecutiveZeros++;
            if (consecutiveZeros == 3)
            {
                return true; /* Found three consecutive zeros */
            }
        }
        else
        {
            consecutiveZeros = 0; /* Reset if a non-zero digit is encountered */
        }
        number /= 10; /* Move to the next digit */
    }

    return false; /* Did not find three consecutive zeros */
}

int main(void)
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (hasThreeConsecutiveZeros(number))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return EXIT_SUCCESS;
}
