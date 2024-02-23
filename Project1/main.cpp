#include "GameFunctions.h"
#include "TicTacToe.h"

int main()
{
    std::vector<std::vector<char>> board;
    int rows, cols;
    initializeGame(board, rows, cols);
    playGame(board, rows, cols);
    return 0;
}
