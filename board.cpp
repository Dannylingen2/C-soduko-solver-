#include <iostream>
#include "board.h"
pos newPos(int x, int y)
{
    pos current;
    current.x = x;
    current.y = y;
    return current;
}
board *newBoard()
{
    int height = 9;
    int width = 9;
    board *currentBoard = new board;
    int **x = new int *[width];
    for (int i = 0; i < width; i++)
    {
        x[i] = new int[height];
        for (int j = 0; j < height; j++)
        {
            x[i][j] = 0;
        }
    }
    currentBoard->width = width;
    currentBoard->height = height;
    return currentBoard;
}
void setSquare(board currentBoard, pos currentPos, int v)
{
    currentBoard.board[currentPos.x][currentPos.y] = v;
}
int getSquare(board currentBoard, pos currentPos)
{
    return currentBoard.board[currentPos.x][currentPos.y];
}
void showBoard(board currentBoard)
{
}
int main()
{
    board *boardtes = newBoard();
    std::cout << boardtes->height << "\n";
    std::cout << "welcome";
}