/*******************************************************************
 * Student Name: Vicente Mba Engung
 * Student Number: 041029226
 * Course: 23S_CST8234
 * Declaration:
 * This is my own original work except where sources have been cited.
 *******************************************************************/

#ifndef STUDENT_H
#define STUDENT_H

struct student
{
    int studentID;
    double percentMark;
};

char *getLetterGrade(double percentMark);
int comparePercentMark(const void *a, const void *b);

#endif
