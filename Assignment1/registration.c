#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "course.h"

/**
 * Function Name: manageRegistration
 * Purpose: Manages the registration process for students into courses and handles related actions.
 * Function in parameters:
 *     - numStudents: Integer representing the number of students
 *     - numCourses: Integer representing the number of courses
 *     - studentIDs: Array storing student IDs as integers
 *     - courseCodes: 2D array storing course codes as strings
 * Function out parameters: None
 * Version: 1
 * Author: Vicente Mba Engung
 */
void manageRegistration(int numStudents, int numCourses, int studentIDs[], char (*courseCodes)[8])
{
    int i, j;
    int choice;
    int studentIndex, courseIndex;
    int studentID;
    char courseCode[8];
    int inputCheck;

    /* Create a registration table */
    int **registrationTable = (int **)malloc(numStudents * sizeof(int *));
    if (registrationTable == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    for (i = 0; i < numStudents; ++i)
    {
        registrationTable[i] = (int *)malloc(numCourses * sizeof(int));
        if (registrationTable[i] == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }
    }

    /* Initialize registration table */
    for (i = 0; i < numStudents; ++i)
    {
        for (j = 0; j < numCourses; ++j)
        {
            registrationTable[i][j] = 0;
        }
    }

    do
    {
        printf("\nChoose an action:\n");
        printf("1. Register a student into a course\n");
        printf("2. Drop a student from a course\n");
        printf("3. Display Registration table\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        /* Input validation */
        inputCheck = scanf("%d", &choice);
        if (inputCheck != 1)
        {
            /* Prints error mesaage if input validation fails */
            printf("Invalid option. Enter an option from 1 — 4.\n");
            while (getchar() != '\n')
                continue;
        }
        /* Check if user input is less than 0 or grater than 4 */
        else if (choice < 0 || choice > 4)
        {
            /* Prints error mesaage if input validation fails */
            printf("Invalid option. Enter an option from 1 — 4.\n");
        }
        else
        {
            switch (choice)
            {
            case 1:
                /* Display current student IDs */
                printf("\nList of Student IDs:\n");
                for (i = 0; i < numStudents; ++i)
                {
                    printf("Student %d ID:\t%d\n", i + 1, studentIDs[i]);
                }

                while (1)
                {
                    printf("\nEnter student ID [5-digits] to be registered: ");
                    scanf("%d", &studentID);

                    studentIndex = findStudentIndex(numStudents, studentIDs, studentID);
                    if (studentIndex == -1)
                    {
                        printf("Student not found!\n");
                        while (getchar() != '\n')
                            continue;
                    }
                    else
                    {
                        break;
                    }
                }

                /* Display number of courses available */
                printf("\nList of Available Course IDs:\n");
                for (i = 0; i < numCourses; i++)
                {
                    printf("Course %d ID:\t%s\n\n", i + 1, courseCodes[i]);
                }

                while (1)
                {
                    printf("Enter Course ID [3-Alphas] [4-Digits]: ");
                    scanf("%7s", courseCode);

                    courseIndex = findCourseIndex(numCourses, courseCodes, courseCode);
                    if (courseIndex == -1)
                    {
                        printf("Course not found!\n");
                        while (getchar() != '\n')
                            continue;
                    }
                    else
                    {
                        break;
                    }
                }

                registrationTable[studentIndex][courseIndex] = 1;
                printf("\nStudent %d registered in course %s.\n", studentID, courseCode);
                break;

            case 2:
                /* Display current student IDs */
                printf("\nList of Student IDs:\n");
                for (i = 0; i < numStudents; ++i)
                {
                    printf("Student %d ID:\t%d\n", i + 1, studentIDs[i]);
                }
                while (1)
                {
                    printf("\nEnter student ID [5-digits] to be dropped: ");
                    scanf("%d", &studentID);

                    studentIndex = findStudentIndex(numStudents, studentIDs, studentID);
                    if (studentIndex == -1)
                    {
                        printf("Student not found!\n");
                        while (getchar() != '\n')
                            continue;
                    }
                    else
                    {
                        break;
                    }
                }

                /* Display number of courses available */
                printf("\nList of Available Course IDs:\n");
                for (i = 0; i < numCourses; i++)
                {
                    printf("Course %d ID:\t%s\n\n", i + 1, courseCodes[i]);
                }

                while (1)
                {
                    printf("Enter course ID [3-Alphas] [4-Digits]: ");
                    scanf("%7s", courseCode);

                    courseIndex = findCourseIndex(numCourses, courseCodes, courseCode);
                    if (courseIndex == -1)
                    {
                        printf("Course not found!\n");
                        while (getchar() != '\n')
                            continue;
                    }
                    else
                    {
                        break;
                    }
                }

                if (registrationTable[studentIndex][courseIndex] == 0)
                {
                    printf("Student %d is not registered in course %s.\n", studentID, courseCode);
                }
                else
                {
                    registrationTable[studentIndex][courseIndex] = 0;
                    printf("Student %d dropped from course %s.\n", studentID, courseCode);
                }
                break;

            case 3:
                printf("\nRegistration Table:\n");
                printf("Student IDs | Course IDs | Status\n");
                for (i = 0; i < numStudents; ++i)
                {
                    for (j = 0; j < numCourses; ++j)
                    {
                        printf("%11d | %-10s | %c\n", studentIDs[i], courseCodes[j], (registrationTable[i][j] == 1) ? 'R' : 'D');
                    }
                }
                break;

            case 4:
                printf("Quitting the program...\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
            }
        }
    } while (choice != 4);
}
