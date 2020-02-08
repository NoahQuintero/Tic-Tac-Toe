#pragma once

#include <exception>

class IllegalMoveException : std::exception {
	private:
		int x, y;
	public:
		IllegalMoveException(int x, int y) {
			this->x = x;
			this->y = y;
		};

		int* get_coordinates() {
			int coords [2];
			coords[0] = this->x;
			coords[1] = this->y;

			return coords;
		};
};


