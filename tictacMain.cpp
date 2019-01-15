#include "tictac.h"

int main() {

	Game a;

	int count = 0;
	bool gameOver = false;
	char gameBoard[row][col]{ 0 };

	std::cout << "Lets Play X's and O's" << '\n' << '\n';
	a.instructions(); //how can i make it lag at too bad then clear then draw board?

	do
	{
		a.drawBoard(gameBoard);
		a.humanMove(gameBoard);
		count++;
		if (count < 5) {
			a.computerMove(gameBoard, count);
		}
		system("cls");
		if (a.isWin(gameBoard, a.getMarker('h')) || a.isWin(gameBoard, a.getMarker('c')) || count == 5) {
			gameOver = true;
		}

	} while (!gameOver);

	a.drawBoard(gameBoard);

	if (a.isWin(gameBoard, a.getMarker('h'))) {
		std::cout << '\t' << "YOU WIN\n";
	}
	else if(a.isWin(gameBoard, a.getMarker('c'))) {
		std::cout << '\t' << "YOU LOSE\n";
	}
	else {
		std::cout << '\t' << "DRAW\n";
	}

}
