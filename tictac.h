#ifndef TICTAC_H
#define TICTAC_H

#include <iostream>
#include <iomanip>

const int row{ 3 }, col{ 3 };

class Game {
	char human{ 'X' };
	char computer{ 'O' };

public:
void drawBoard(const char gameboard[row][col]); 
void instructions();
void humanMove(char gameboard[row][col]);
bool isEmpty(const char gameboard[row][col], int rw, int cl);
bool isValid(int rw, char cl);
bool isWin(const char gameboard[row][col], char marker);
char getMarker(char marker);
void computerMove(char gameboard[row][col], int move);
bool threat(char gameboard[row][col]);
void attack(char gameboard[row][col]);
bool goForWin(char gameboard[row][col]);

};

#endif // !TICTAC_H
