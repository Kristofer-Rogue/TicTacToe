#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>

struct Move {
    int row;
    int col;
};

bool isValidMove(const std::vector<std::vector<char>>& board, int row, int col);
bool makeMove(std::vector<std::vector<char>>& board, int row, int col, char player);
void printBoard(const std::vector<std::vector<char>>& board);
bool checkWin(const std::vector<std::vector<char>>& board, char player);
bool checkTie(const std::vector<std::vector<char>>& board);
Move getPlayerMove(const std::vector<std::vector<char>>& board);

#endif
