#include "tictac.h"

void Game::drawBoard(const char gameboard[row][col]) {

	std::cout << std::setw(5) << "A" << std::setw(6) << "B" << std::setw(6) << "C" << '\n';
	std::cout << " +-----+-----+-----+" << '\n';
	std::cout << "0" << "|" << std::setw(3) << gameboard[0][0] << std::setw(3) << "|" << std::setw(3) << gameboard[0][1] << std::setw(3) << "|" << std::setw(3) << gameboard[0][2] << std::setw(3) << "|" << '\n';
	std::cout << " +-----+-----+-----+" << '\n';
	std::cout << "1" << "|" << std::setw(3) << gameboard[1][0] << std::setw(3) << "|" << std::setw(3) << gameboard[1][1] << std::setw(3) << "|" << std::setw(3) << gameboard[1][2] << std::setw(3) << "|" << '\n';
	std::cout << " +-----+-----+-----+" << '\n';
	std::cout << "2" << "|" << std::setw(3) << gameboard[2][0] << std::setw(3) << "|" << std::setw(3) << gameboard[2][1] << std::setw(3) << "|" << std::setw(3) << gameboard[2][2] << std::setw(3) << "|" << '\n';
	std::cout << " +-----+-----+-----+" << '\n' << '\n';
}

void Game::instructions() {
	char ready = 0;
	std::cout << "hello and welcome to tic tac toe!" << '\n' << '\n';
	std::cout << "you will be playing as x!" << '\n';
	std::cout << "in order to make a move: " << '\n' << "\tplease enter a number to indicate the row followed by a letter to indicate the column." << '\n';
	std::cout << "\tnote: character must be Uppercase" << '\n';
	std::cout << "ready?? (y/n) ";
	std::cin >> ready;
	if (ready == 'y' || ready == 'y') {
		std::cout << "\tgreat! goodluck" << '\n';
	}
	else {
		std::cout << "\ttoo bad!!" << '\n';
	}
}

void Game::humanMove(char gameboard[row][col]) {
	int rw; char cl; 

	do
	{
		std::cout << "Please Make a Valid Move: ";

		do
		{
			std::cin >> rw >> cl;
			if (std::cin.fail()) {
				std::cin.clear();
				rw = -1;
				cl = 0;
				std::cin.ignore(200000,'\n');
			}

		} while (!isValid(rw, cl));


	} while (!isEmpty(gameboard, rw, (cl - 'A')));

	gameboard[rw][cl - 'A'] = human;
	std::cin.ignore();
	std::cin.clear();

}

bool Game::isEmpty(const char gameboard[row][col], int rw, int cl) {
	bool empty = true;
	if (gameboard[rw][cl] == human || gameboard[rw][cl] == computer) {
		empty = false;
	}
	return empty;
}

bool Game::isValid(int rw, char cl) {
	bool valid = true;
	if (rw < 0 || rw > 2 || cl < 'A' || cl > 'C') {
		std::cout << "invalid input please enter a valid coordinate!" << '\n';
		valid = false;
	}
	return valid;
}

bool Game::isWin(const char gameboard[row][col], char marker) {
	bool win = false;
	for (int rw = 0; rw < row; rw++) {
		for (int cl = 0; cl < col; cl++) {

			//horizontal win
			if (cl == 0 && (rw == 0 || rw == 1 || rw == 2)) {
				if (gameboard[rw][cl] == marker && gameboard[rw][cl + 1] == marker && gameboard[rw][cl + 2] == marker) {
					win = true;
				}
			}

			//vertical win
			if (rw == 0 && (cl == 0 || cl == 1 || cl == 2)) { 
				if (gameboard[rw][cl] == marker && gameboard[rw + 1][cl] == marker && gameboard[rw + 2][cl] == marker) {
					win = true;
				}
			}

			//diagonal win
			if (rw == 1 && cl == 1) {
				if (gameboard[rw][cl] == marker && gameboard[rw + 1][cl + 1] == marker && gameboard[rw - 1][cl - 1] == marker) {
					win = true;
				}
				else if (gameboard[rw][cl] == marker && gameboard[rw - 1][cl + 1] == marker && gameboard[rw + 1][cl - 1] == marker) {
					win = true;
				}
			}
		}
	}

	return win;
}

char Game::getMarker(char marker) {
	marker == 'h' ? (marker = human) : (marker = computer);
	return marker;
}

void Game::computerMove(char gameboard[row][col], int move) {
	if (move == 1) {
		bool check = isEmpty(gameboard, 1, 1);
		std::cout << '\n' << check << '\n';
		if (check) {
			gameboard[1][1] = computer;
		}
		else {
			gameboard[0][0] = computer;
		}
	}
	else {

		bool neutralized = threat(gameboard);

		if (!neutralized) {
			attack(gameboard);
		}
	}
}

bool Game::threat(char gameboard[row][col]) {
	bool neutralized = false;
	neutralized = goForWin(gameboard);
	if (!neutralized) {
		for (int rw = 0; rw < row; rw++) {
			for (int cl = 0; cl < col; cl++) {
				if (isEmpty(gameboard, rw, cl)) {
					gameboard[rw][cl] = human;
					if (isWin(gameboard, human)) {
						gameboard[rw][cl] = computer;
						neutralized = true;
						return neutralized;
					}
					else {
						gameboard[rw][cl] = NULL;
					}
				}
			}
		}
	}
	return neutralized;
}

bool Game::goForWin(char gameboard[row][col]) {
	bool won = false;
	for (int rw = 0; rw < row; rw++) {
		for (int cl = 0; cl < col; cl++) {
			if (isEmpty(gameboard, rw, cl)) {
				gameboard[rw][cl] = computer;
				if (isWin(gameboard, computer)) {
					won = true;
					return won;
				}
				else {
					gameboard[rw][cl] = NULL;
				}
			}
		}

	}
	return won;
}

void Game::attack(char gameboard[row][col]) {
	bool won = goForWin(gameboard);
	if (!won) {
		for (int rw = 0; rw < row; rw++) {
			for (int cl = 0; cl < col; cl++) {
				if (isEmpty(gameboard, rw, cl)) {
					gameboard[rw][cl] = computer;
					return;
				}
			}
		}
	}
}







