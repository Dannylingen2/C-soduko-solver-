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

    currentBoard->board = new int[width * height];
    currentBoard->width = width;
    currentBoard->height = height;
    return currentBoard;
}
void setSquare(board *currentBoard, pos currentPos, int v)
{
    // [i][j] is then rewritten as [i * sizeY + j] so that we use one chunk of memory
    if (v > 0 && v < 10)
    {
        currentBoard->board[currentPos.y * currentBoard->height + currentPos.x] = v;
    }
    else
    {
        std::cout << "not a valid number " << v;
    }
}
int getSquare(board *currentBoard, pos currentPos)
{
    return currentBoard->board[currentPos.y * currentBoard->height + currentPos.x];
}
void showBoard(board *currentBoard)
{
    int height = currentBoard->height;
    int width = currentBoard->width;
    std::cout << "|---|---|---| \n";
    for (int y = 0; y < height; y++)
    {
        if (y == 3 || y == 6)
            std::cout << "|---|---|---| \n";

        std::cout << "|";
        for (int x = 0; x < width; x++)
        {
            if (x == 3 || x == 6)
                std::cout << "|";
            std::cout << currentBoard->board[y * height + x];
        }
        std::cout << "|\n";
    }
    std::cout << "|---|---|---| \n\n\n";
}
