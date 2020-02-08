#pragma once

#include <ostream>
#include "IllegalMoveException.h"

class TicTacToeBoard {
private:
    char** board;
    int size;

    char check_columns(void) {
        int i, j = 0;

        char player = NULL;
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                char play = board[i][j];
                // nobody played here, so there can't be a win
                if (play == NULL) {
                    // quit
                    break;
                }
                // first cell, record the player
                else if (player == NULL) {
                    player = play;
                }

                // is there an interfering move?
                if (player != play) {
                    // if so, null out the player, and quit
                    player = NULL;
                    break;
                }

            }

            // did the check go uninterfered?
            if (player != NULL) {
                // if so, quit
                break;
            }
        }

        return player;
    }

    char check_rows(void) {
        int i, j = 0;

        char player = NULL;
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                char play = board[j][i];
                // nobody played here, so there can't be a win
                if (play == NULL) {
                    // quit
                    break;
                }
                // first cell, record the player
                else if (player == NULL) {
                    player = play;
                }

                // is there an interfering move?
                if (player != play) {
                    // if so, null out the player, and quit
                    player = NULL;
                    break;
                }

            }

            // did the check go uninterfered?
            if (player != NULL) {
                // if so, quit
                break;
            }
        }

        return player;
    }

    char check_diagonals(void) {

        char player = NULL;

        // check 0,0 to size,size

        for (int i = 0; i < size; i++) {
            char play = board[i][i];

            // nobody played here, so there can't be a win
            if (play == NULL) {
                // quit
                break;
            }
            // first cell, record the player
            else if (player == NULL) {
                player = play;
            }

            // is there an interfering move?
            if (player != play) {
                // if so, null out the player, and quit
                player = NULL;
                break;
            }
        }

        // if player is null, we didn't find a win, check the other direction
        if (player == NULL) {
            // now check size,0 to 0,size
            int opp_coord = size - 1;
            for (int i = 0; i < size; i++) {
                char play = board[i][opp_coord];

                // nobody played here, so there can't be a win
                if (play == NULL) {
                    // quit
                    break;
                }
                // first cell, record the player
                else if (player == NULL) {
                    player = play;
                }

                // is there an interfering move?
                if (player != play) {
                    // if so, null out the player, and quit
                    player = NULL;
                    break;
                }

                opp_coord--;

            }
        }
        // by this point, player is the winning player, or null indicating no win

        return player;
    }

public:
    TicTacToeBoard(void) {
        size = 3;
        TicTacToeBoard(size);
    }

    TicTacToeBoard(int size) {
        this->size = size;

        // a multi-dimensional array is an array of pointers
        board = new char* [size];

        // initialize each of those to be char[]
        for (int i = 0; i < size; i++) {
            char* row = new char[size];

            for (int j = 0; j < size; j++) {
                row[j] = NULL;
            }

            board[i] = row;
        }
    }

    ~TicTacToeBoard() {
        for (int i = 0; i < size; i++) {
            delete board[i];
        }

        delete board;
    }

    // read more about friend functions, seems friend functions are allowed to access private members?
    friend std::ostream& operator<<(std::ostream& stream, const TicTacToeBoard& board);

    bool make_player_move(int x, int y, char player) {
        bool move_made = false;

        // check either x or y is out of bounds
        if (x > size || y > size) {
            throw new IllegalMoveException(x, y);
        }

        // could we do this with pointers instead of double array access?
        if (board[x][y] == NULL) {
            board[x][y] = player;
            move_made = true;
        }

        return move_made;
    }

    char is_game_won(void) {
        char winner;

        winner = check_columns();

        if (winner == NULL) {
            winner = check_rows();
        }

        if (winner == NULL) {
            winner = check_diagonals();
        }

        return winner;
    }

};



