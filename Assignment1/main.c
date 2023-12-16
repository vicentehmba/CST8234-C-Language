/******************************************************
 * Title: Assignment #1 - Student Registration System
 * Course: CST8234 C Language
 * @Author: Vicente Mba Engung (041029226)
 * Lab Section: 011
 * Professor: Surbhi Bahri
 * Due date: 11/19/23
 * Submission date: 11/19/23
 ******************************************************/

/* Status:
 * Requirement #1: {complete}
 * Requirement #2: {complete}
 * Requirement #3: {complete}
 * Requirement #4: {complete}
 * Requirement #5: {complete}
 * Requirement #6: {complete}
 * Requirement #7: {complete}
 * Requirement #8: {complete}
 * Requirement #9: {complete}
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "student.h"
#include "course.h"
#include "registration.h"

/**
 * Function Name: main
 * Purpose: Entry point of the Student Registration System program.
 *          Allows users to register students for courses based on provided IDs and codes.
 *          Manages memory allocation, user input validation, and registration process.
 *          Utilizes functions from "student.h", "course.h", and "registration.h".
 * Author: Vicente Mba Engung
 * Date: 11/19/23
 * Version: 1
 * @return Integer (return code)
 */
int main(void)
{
    int numStudents, numCourses;
    int *studentIDs = NULL;
    char(*courseCodes)[8];
    int i;
    int tempID;
    char tempCode[8];
    int inputCheck;

    printf("Welcome to Student Registration System.\n\n");

    /* Input validation for number of students to be registered */
    while (1)
    {
        /* Get the number of students */
        printf("Enter the number of students: ");
        inputCheck = scanf("%d", &numStudents);
        if (inputCheck != 1 || numStudents <= 0)
        {
            printf("\nNumber of students must be a positive integer.\n\n");
            while (getchar() != '\n')
                continue;
        }
        else
        {
            break;
        }
    }

    /* Allocate memory for student IDs after getting numStudents */
    studentIDs = (int *)malloc(numStudents * sizeof(int));
    if (studentIDs == NULL)
    {
        printf("Memory allocation failed.\n");
        return -1;
    }

    /* Get student IDs */
    for (i = 0; i < numStudents; ++i)
    {
        printf("Enter student %d ID [5-digits]: ", i + 1);
        do
        {
            inputCheck = scanf("%d", &tempID);
            if (inputCheck != 1 || tempID < 10000 || tempID > 99999)
            {
                printf("Invalid student ID! Please enter a [5-digits] ID: ");
                while (getchar() != '\n')
                    continue;
            }
        } while (tempID < 10000 || tempID > 99999);
        studentIDs[i] = tempID;
    }

    /* Input validation for number of courses available */
    while (1)
    {
        /* Get the number of courses */
        printf("Enter the number of courses: ");
        inputCheck = scanf("%d", &numCourses);
        if (inputCheck != 1 || numCourses <= 0)
        {
            printf("\nNumber of students must be a positive integer.\n\n");
            while (getchar() != '\n')
                continue;
        }
        else
        {
            break;
        }
    }

    /* Allocate memory for courseCodes after getting numCourses */
    courseCodes = (char(*)[8])malloc(numCourses * sizeof(char[8]));
    if (courseCodes == NULL)
    {
        free(studentIDs);
        printf("Memory allocation failed.\n");
        return -1;
    }

    /* Get course codes */
    for (i = 0; i < numCourses; ++i)
    {
        printf("Enter Course %d ID [3-Alphas] [4-Digits]: ", i + 1);
        do
        {
            scanf("%7s", tempCode);
            if (strlen(tempCode) != 7 || !isalpha(tempCode[0]) || !isalpha(tempCode[1]) || !isalpha(tempCode[2]))
            {
                printf("Invalid course ID! Please enter a [3-Alphas] [4-Digits] ID: ");
            }
        } while (strlen(tempCode) != 7 || !isalpha(tempCode[0]) || !isalpha(tempCode[1]) || !isalpha(tempCode[2]));
        strcpy(courseCodes[i], tempCode);
    }

    /* Manage registration */
    manageRegistration(numStudents, numCourses, studentIDs, courseCodes);

    /* Free allocated memory */
    free(studentIDs);
    free(courseCodes);

    return 0;
}
