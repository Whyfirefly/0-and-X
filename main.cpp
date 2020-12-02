//крестики-нолики
#include <iostream>
#include "Game.h"
#include "Input_Output.h"

using namespace std;

int main() {
    const int SIZE = 3;
    int row;
    int stolb;

    char board[SIZE][SIZE] = {{' ', ' ', ' '},
                              {' ', ' ', ' '},
                              {' ', ' ', ' '}};

    bool winX, win0 = false, draw; //определения выигрыша x,0 и ничья

    PrintBoard(board, SIZE);

    do {
        cout << "!!!X!!!" << endl;
        do { //TODO перенести в функцию
            row = InputCoordinate();
            stolb = InputCoordinate();
        } while (board[row][stolb] != ' '); //проверяем пусто ли поле по указанным координатам. если не пусто, повторяем. Если пусто, ставим крестик
        board[row][stolb] = 'X';
        PrintBoard(board, SIZE);
        winX = WinX(board, SIZE);
        if (winX) break;

        cout << "!!!0!!!" << endl;
        do {
            row = InputCoordinate();
            stolb = InputCoordinate();
        } while (board[row][stolb] != ' ');
        board[row][stolb] = '0';
        PrintBoard(board, SIZE);
        win0 = Win0(board);
        if (Win0) break;

        draw = Draw(board, SIZE);
    } while (!draw);

    if (winX) {
        cout << "Winner is X" << endl;
    } else if (win0) {
        cout << "Winner is 0" << endl;
    } else {
        cout << "Nobody won!" << endl;
    }
}

