#include <stdio.h>
#include <string.h>
#include "course.h"

/**
 * Function Name: displayCourses
 * Purpose: Display the list of course IDs.
 * Function in parameters:
 *     - numCourses: Integer representing the number of courses
 *     - courseCodes: 2D array storing course codes as strings
 * Function out parameters: None
 * Version: 1
 * Author: Vicente Mba Engung
 */
void displayCourses(int numCourses, char courseCodes[][8])
{
    int i;

    printf("Course IDs:\n");
    for (i = 0; i < numCourses; ++i)
    {
        printf("%s\n", courseCodes[i]);
    }
}

/**
 * Function Name: findCourseIndex
 * Purpose: Find the index of a specific course code in the array of course codes.
 * Function in parameters:
 *     - numCourses: Integer representing the number of courses
 *     - courseCodes: 2D array storing course codes as strings
 *     - courseCode: String representing the course code to be found
 * Function out parameters:
 *     - Returns the index of the course code if found; otherwise, returns -1
 * Version: 1
 * Author: Vicente Mba Engung
 */
int findCourseIndex(int numCourses, char courseCodes[][8], char courseCode[])
{
    int i;

    for (i = 0; i < numCourses; ++i)
    {
        if (strcmp(courseCodes[i], courseCode) == 0)
        {
            return i;
        }
    }
    return -1; /* Not found */
}
