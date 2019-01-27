# Tic Tac Toe V0

First Version of a Small Game Implementing a smart (AI) Computer Opponent Using the C++ Programming Language. 

Computer (AI) Design:

//First move is made to one of two ideal positions

//Subsequently check for threat, if no threat present go for attack, within attack go for win otherwise go for first empty spot

//The functions threat() and goForWin() look one move ahead and respond accordingly

Improvements for next Version:

//Clean up the structure of the code and redesign the implementation

//Firstly, the checkWin function unecessarily loops through everything we can easily prune the number of loops in accordance with a winnning game state

//Secondly, main.cpp should not have you gameplay this should be its own function

//Finally, use recursion to play the best possible move. The flaw is AI can only see one move ahead and it prioritizes threat over attack recusrion will ensure best play everytime

