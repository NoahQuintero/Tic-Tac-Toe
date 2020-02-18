#include "TicTacToeGame.h"

std::ostream& operator<<(std::ostream& stream, const TicTacToeGame& game) {
    stream << game.board;

    return stream;
}