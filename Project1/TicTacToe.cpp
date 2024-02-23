#include "TicTacToe.h"
#include <iostream>

bool isValidMove(const std::vector<std::vector<char>>& board, int row, int col)
{
    return row >= 0 && row < board.size() && col >= 0 && col < board[row].size() && board[row][col] == '_';
}

bool makeMove(std::vector<std::vector<char>>& board, int row, int col, char player)
{
    if (isValidMove(board, row, col)) {
        board[row][col] = player;
        return true;
    }
    return false;
}

void printBoard(const std::vector<std::vector<char>>& board)
{
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

bool checkWin(const std::vector<std::vector<char>>& board, char player)
{
    size_t size = board.size();

    for (size_t i = 0; i < size; ++i) {
        bool rowWin = true;
        bool colWin = true;
        for (size_t j = 0; j < size; ++j) {
            if (board[i][j] != player)
                rowWin = false;
            if (board[j][i] != player)
                colWin = false;
        }
        if (rowWin || colWin)
            return true;
    }

    bool diag1Win = true;
    bool diag2Win = true;
    for (size_t i = 0; i < size; ++i) {
        if (board[i][i] != player)
            diag1Win = false;
        if (board[i][size - i - 1] != player)
            diag2Win = false;
    }
    return diag1Win || diag2Win;
}

bool checkTie(const std::vector<std::vector<char>>& board)
{
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == '_')
                return false;
        }
    }
    return true;
}

Move getPlayerMove(const std::vector<std::vector<char>>& board)
{
    int row, col;
    std::cout << "Enter row (1-" << board.size() << "): ";
    std::cin >> row;
    std::cout << "Enter column (1-" << board[0].size() << "): ";
    std::cin >> col;
    return { row - 1, col - 1 };
}
