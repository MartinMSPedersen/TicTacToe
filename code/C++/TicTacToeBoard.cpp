#include "TicTacToeBoard.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>

using namespace std;

TicTacToeBoard::TicTacToeBoard()
{
	//whoToMove = "X";
	is_game_over = false;
	//winner = "";
	//lastMove = "";
	for (unsigned int row=0; row<3; row++)
		for (unsigned int col=0; col<3; col++)
			board[row][col] = '-';
	emptyPlaces.push_back("A1");
	emptyPlaces.push_back("A2");
	emptyPlaces.push_back("A3");
	emptyPlaces.push_back("B1");
	emptyPlaces.push_back("B2");
	emptyPlaces.push_back("B3");
	emptyPlaces.push_back("C1");
	emptyPlaces.push_back("C2");
	emptyPlaces.push_back("C3");
}

ostream& operator<< (ostream& o, TicTacToeBoard& tb) 
{
	string result;
	if (tb.is_game_over == false) {
		result.append("is_game_over = false\n");
	} else {
		result.append("is_game_over = true\n");
	}
	return o << result;
}
