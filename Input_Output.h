#ifndef INC_2_INPUT_OUTPUT_H
#define INC_2_INPUT_OUTPUT_H
#include <iostream>
#include "Game.h"

using namespace std;

//выводим плато крестики-нолики
void PrintBoard(char board[][3], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << board[i][j] << "| ";
        }
        cout << endl << "---------" << endl;
    }
}

/*
 * ввод координаты пользователем
 */
int InputCoordinate() {
    int coordinate;
    do {
        cout << "Enter the coordinate from 0 to 2: ";
        cin >> coordinate;
    } while (!Check(coordinate));
    return coordinate;
}

#endif //INC_2_INPUT_OUTPUT_H
