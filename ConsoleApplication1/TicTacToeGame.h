#pragma once

#include <ostream>
#include "TicTacToeBoard.h"

class TicTacToeGame {
private:
	int numPlayers;
	char* playerChars;
	int turn;

	TicTacToeBoard* board;

public:
	TicTacToeGame(int numPlayers, char* playerChars, int boardSize) {
		this->numPlayers = numPlayers;
		this->playerChars = playerChars;
		this->turn = 0;

		this->board = new TicTacToeBoard(boardSize);
	}

	~TicTacToeGame() {
		delete board;
	}

	friend std::ostream& operator<<(std::ostream& stream, const TicTacToeGame& game);

	bool play_turn(int x, int y) {
		bool play_made = false;
		try {
			// get the current player
			char currentPlayer = this->playerChars[turn];

			// attempt to make this move
			play_made = this->board->make_player_move(x, y, currentPlayer);
		}
		catch (IllegalMoveException e) {
			// throw the illegal move exception if it occurs
			throw e;
		}

		// if move was successfully made, increment the turn. Bring it back to 0 if necessary
		if (play_made) {
			turn++;
			if (turn > numPlayers) {
				turn = 0;
			}
		}

		return play_made;
	}

	char is_game_won(void) {
		return this->board->is_game_won();
	}

	int get_current_turn(void) {
		return this->turn;
	}

	char get_current_player(void) {
		return this->playerChars[this->turn];
	}
};

