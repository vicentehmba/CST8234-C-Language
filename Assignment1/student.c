#include <stdio.h>
#include "student.h"

/**
 * Function Name: displayStudents
 * Purpose: Display the list of student IDs.
 * Function in parameters:
 *     - numStudents: Integer representing the number of students
 *     - studentIDs: Array storing student IDs as integers
 * Function out parameters: None
 * Version: 1
 * Author: Vicente Mba Engung
 */
void displayStudents(int numStudents, int studentIDs[])
{
    int i;

    printf("Student IDs:\n");
    for (i = 0; i < numStudents; ++i)
    {
        printf("%d\n", studentIDs[i]);
    }
}

/**
 * Function Name: findStudentIndex
 * Purpose: Find the index of a specific student ID in the array of student IDs.
 * Function in parameters:
 *     - numStudents: Integer representing the number of students
 *     - studentIDs: Array storing student IDs as integers
 *     - studentID: Integer representing the student ID to be found
 * Function out parameters:
 *     - Returns the index of the student ID if found; otherwise, returns -1
 * Version: 1
 * Author: Vicente Mba Engung
 */
int findStudentIndex(int numStudents, int studentIDs[], int studentID)
{
    int i;

    for (i = 0; i < numStudents; ++i)
    {
        if (studentIDs[i] == studentID)
        {
            return i;
        }
    }
    return -1; /* Not found */
}
