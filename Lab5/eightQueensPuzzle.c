/*******************************************************************
 * Student Name: Vicente Mba Engung
 * Student Number: 041029226
 * Course: 23S_CST8234
 * Declaration:
 * This is my own original work except where sources have been cited.
 *******************************************************************/

#include <stdio.h>
#include "eightQueensPuzzle.h"

/* Function to initialize the chess board with empty spaces */
void initializeBoard(char board[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = ' ';
        }
    }
}

/* Function to print the chess board with queens marked as 'Q' and empty cells as spaces */
void printBoard(char board[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (j == 0)
            {
                printf("+---");
            }
            else
            {
                printf("+---");
            }
        }
        printf("+\n");
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == 'Q')
            {
                printf("| Q ");
            }
            else
            {
                printf("|   ");
            }
        }
        printf("|\n");
    }
    for (int j = 0; j < 8; j++)
    {
        printf("+---");
    }
    printf("+\n");
}

/* Function to modify the board at a specified row and column with a specified value */
void modifyBoard(char board[8][8], int row, int col, char value)
{
    board[row][col] = value;
}

/* Function to check if a queen placed at a specific row and column is safe */
int isSafe(char board[8][8], int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
    {
        if (board[row][i] == 'Q')
        {
            return 0;
        }
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return 0;
        }
    }
    for (i = row, j = col; j >= 0 && i < 8; i++, j--)
    {
        if (board[i][j] == 'Q')
        {
            return 0;
        }
    }
    return 1;
}

/* Recursive function to place the queens on the board */
int placeQueens(char board[8][8], int col)
{
    if (col >= 8)
    {
        return 1;
    }
    for (int i = 0; i < 8; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 'Q';
            if (placeQueens(board, col + 1))
            {
                return 1;
            }
            board[i][col] = ' ';
        }
    }
    return 0;
}

/* Function to solve the Eight Queens Puzzle */
int solveEightQueens()
{
    char board[8][8];
    initializeBoard(board);
    if (placeQueens(board, 0) == 0)
    {
        printf("Solution does not exist");
        return 0;
    }
    printBoard(board);
    return 1;
}
