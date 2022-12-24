#include "board.h"
#include "logic.h"
#include <iostream>

bool checkRow(board *currentBoard, int row, int number)
{
    for (int column = 0; column < currentBoard->width; column++)
    {
        pos current = newPos(column, row);
        if (getSquare(currentBoard, current) == number)
            return false;
    }
    return true;
}
bool checkColumn(board *currentBoard, int column, int number)
{
    for (int column = 0; column < currentBoard->width; column++)
    {
        pos current = newPos(column, column);
        if (getSquare(currentBoard, current) == number)
            return false;
    }
    return true;
}
bool checkSqaure(board *currentBoard, pos currentPos, int number)
{
    int xQuad = (currentPos.x / 3) * 3;
    int yQuad = (currentPos.y / 3) * 3;
    for (int y = yQuad; y < yQuad + 3; y++)
    {
        for (int x = xQuad; x < xQuad + 3; x++)
        {
            pos current = newPos(x, y);
            if (getSquare(currentBoard, current) == number)
                return false;
        }
    }
    return true;
}
bool placeNumber(board *currentBoard, pos currentPos, int number)
{
    if (checkColumn(currentBoard, currentPos.y, number) &&
        checkRow(currentBoard, currentPos.x, number) &&
        checkSqaure(currentBoard, currentPos, number))
    {
        setSquare(currentBoard, currentPos, number);
        return true;
    }
    return false;
}
#include <iostream>

using namespace std;

// N is the size of the 2D matrix N*N
#define N 9

/* A utility function to print grid */
void print(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

bool solveBoard(board *currentBoard, int row, int col)
{
    if (row == N - 1 && col == N)
        return true;
    if (col == N)
    {
        row++;
        col = 0;
    }
    pos currentPos = newPos(row, col);
    if (getSquare(currentBoard, currentPos) > 0)
        return solveBoard(currentBoard, row, col + 1);

    for (int num = 1; num <= N; num++)
    {

        if (placeNumber(currentBoard, currentPos, num) == true)
        {

            if (solveBoard(currentBoard, row, col + 1))
                return true;
        }

        setSquare(currentBoard, currentPos, 0);
    }
    return false;
}
