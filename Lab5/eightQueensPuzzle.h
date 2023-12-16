/*******************************************************************
 * Student Name: Vicente Mba Engung
 * Student Number: 041029226
 * Course: 23S_CST8234
 * Declaration:
 * This is my own original work except where sources have been cited.
 *******************************************************************/

#ifndef EIGHTQUEENSPUZZLE_H
#define EIGHTQUEENSPUZZLE_H

void initializeBoard(char board[8][8]);
void printBoard(char board[8][8]);
void modifyBoard(char board[8][8], int row, int col, char value);
int isSafe(char board[8][8], int row, int col);
int placeQueens(char board[8][8], int col);
int solveEightQueens(void);

#endif
