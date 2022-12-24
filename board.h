
struct pos
{
    int x;
    int y;
};

typedef pos pos;

pos newPos(int x, int y);

struct board
{
    int *board;
    int height;
    int width;
};

typedef board board;

board *newBoard();
void setSquare(board *currentBoard, pos currentPos, int v);
int getSquare(board *currentBoard, pos currentPos);
void showBoard(board *currentBoard);
