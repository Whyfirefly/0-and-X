#ifndef INC_2_GAME_H
#define INC_2_GAME_H

/*
 * проверяем, что координата входит в диапазон от 0 до 2
 */
bool Check(int number) {
    if (number >= 0 && number <= 2) {
        return true;
    } else {
        return false;
    }
}

/*
 * определяем ничью
 */
bool Draw(char board[][3], int size)
{
    for (int i = 0; i < size; ++i) { //проходимся по всем ячейкам массива. Спрашиваем, если любая ячейка равна пробелу, то возвращаем false
        for (int j = 0; j < size; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

/*
 * определяем победителя (неважно крестик или нолик)
 */
bool Win(char board[][3], char symbol)
{
    if ((board[0][0] == symbol && board[0][1] == symbol && board[0][2] == symbol) || // проверяем одинаковость строк
        (board[1][0] == symbol && board[1][1] == symbol && board[1][2] == symbol) ||
        (board[2][0] == symbol && board[2][1] == symbol && board[2][2] == symbol) ||

        (board[0][0] == symbol && board[1][0] == symbol && board[2][0] == symbol) || //одинаковость столбцов
        (board[0][1] == symbol && board[1][1] == symbol && board[2][1] == symbol) ||
        (board[0][2] == symbol && board[1][2] == symbol && board[2][2] == symbol) ||

        (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) || //диагонали
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol))
    {
        return true;
    } else return false;
}

//функция проверки выигрыша крестика
bool WinX(char board[][3], int size)
{
    bool win = Win(board, 'X');
    return win;
}

//функция проверки выигрыша нолик
bool Win0(char board[][3])
{
    bool win = Win(board, '0');
    return win;
}

#endif //INC_2_GAME_H
