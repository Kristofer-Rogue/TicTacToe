#include "GameFunctions.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

void initializeGame(std::vector<std::vector<char>>& board, int& rows, int& cols)
{
    srand(time(0));
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;
    board = std::vector<std::vector<char>>(rows, std::vector<char>(cols, '_'));
}

void playGame(std::vector<std::vector<char>>& board, int rows, int cols)
{
    const int totalCells = rows * cols;
    char currentPlayer = 'O';
    int movesMade = 0;
    while (true) {
        printBoard(board);
        Move move;
        do {
            std::cout << "Player " << currentPlayer << "'s turn." << std::endl;
            move = getPlayerMove(board);
        } while (!isValidMove(board, move.row, move.col));

        makeMove(board, move.row, move.col, currentPlayer);
        ++movesMade;

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            break;
        } else if (movesMade == totalCells) {
            printBoard(board);
            std::cout << "It's a tie!" << std::endl;
            break;
        }

        currentPlayer = (currentPlayer == 'O') ? 'X' : 'O';
    }
}
