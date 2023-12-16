/*******************************************************************
 * Student Name: Vicente Mba Engung
 * Student Number: 041029226
 * Course: 23S_CST8234
 * Declaration:
 * This is my own original work except where sources have been cited.
 *******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "student.h"

/* Compare function for sorting students by ID */
int compareStudentID(const void *a, const void *b)
{
    return ((struct student *)a)->studentID - ((struct student *)b)->studentID;
}

/* Main function to read student data from file, calculate statistics, and display results */
int main(int argc, char *argv[])
{
    int i;
    int count = 0;
    double average = 0;
    struct student students[100];
    double median;
    char *grade;
    FILE *file;

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "rb");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    while (fread(&students[count], sizeof(struct student), 1, file) == 1)
    {
        count++;
    }
    fclose(file);

    qsort(students, count, sizeof(struct student), compareStudentID);

    for (i = 0; i < count; i++)
    {
        struct student *s = &students[i];
        grade = getLetterGrade(s->percentMark);
        printf("Student ID: %d, Percent Mark: %6.2f, Letter Grade: %s\n", students[i].studentID, students[i].percentMark, grade);
    }

    qsort(students, count, sizeof(struct student), comparePercentMark);
    median = (students[count / 2].percentMark + students[(count - 1) / 2].percentMark) / 2.0;
    for (i = 0; i < count; i++)
    {
        average += students[i].percentMark;
    }
    average /= count;

    printf("\nMedian Percent Mark: %8.2f\n", median);
    printf("Average Percent Mark: %7.2f\n", average);

    return 0;
}
