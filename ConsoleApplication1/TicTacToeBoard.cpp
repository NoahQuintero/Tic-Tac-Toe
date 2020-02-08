#include "TicTacToeBoard.h"

//https://stackoverflow.com/questions/1549930/c-equivalent-of-javas-tostring

// so to control what a class 'prints', we override the << operater on std:ostream
// should read more about this

std::ostream& operator<<(std::ostream& stream, const TicTacToeBoard& board) {
    for (int i = 0; i < board.size; i++) {

        for (int j = 0; j < board.size; j++) {
            char play = board.board[i][j];

            if (play == NULL) {
                play = ' ';
            }

            stream << play;

            if (j != board.size - 1) {
                stream << '|';
            }

        }

        stream << '\n';

        if (i != board.size - 1) {
            for (int j = 0; j < board.size; j++) {
                stream << '-';
            }

        }

        stream << '\n';

    }

    return stream;
}