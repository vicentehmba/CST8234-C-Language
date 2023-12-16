/*******************************************************************
 * Student Name: Vicente Mba Engung
 * Student Number: 041029226
 * Course: 23S_CST8234
 * Declaration:
 * This is my own original work except where sources have been cited.
 *******************************************************************/

#include "student.h"

/* Function to assign a letter grade based on the numeric grade */
char *getLetterGrade(double percent)
{
    if (percent >= 90)
    {
        return "A+";
    }
    else if (percent >= 85)
    {
        return "A";
    }
    else if (percent >= 80)
    {
        return "A-";
    }
    else if (percent >= 77)
    {
        return "B+";
    }
    else if (percent >= 73)
    {
        return "B";
    }
    else if (percent >= 70)
    {
        return "B-";
    }
    else if (percent >= 67)
    {
        return "C+";
    }
    else if (percent >= 63)
    {
        return "C";
    }
    else if (percent >= 60)
    {
        return "C-";
    }
    else if (percent >= 57)
    {
        return "D+";
    }
    else if (percent >= 53)
    {
        return "D";
    }
    else if (percent >= 50)
    {
        return "D-";
    }
    else
    {
        return "F";
    }
}

int comparePercentMark(const void *a, const void *b)
{
    return ((struct student *)a)->percentMark - ((struct student *)b)->percentMark;
}
