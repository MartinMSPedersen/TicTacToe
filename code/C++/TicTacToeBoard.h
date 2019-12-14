#ifndef _TICTACTOEBOARD_H_
#define _TICTACTOEBOARD_H_

#include <iostream>
#include <string>
#include <list>

using namespace std;

class TicTacToeBoard 
{
	public:
		TicTacToeBoard();
		friend ostream& operator<< (ostream& o, TicTacToeBoard& tb);
		bool makeMove(string move);
		bool isGameOver();
		void undoLastMove();
		list<string> emptyPlaces;
		list<string> playedMoves;
	private:
		char whoToMove;
		bool is_game_over;
		char winner;
		string lastMove;
		char board[3][3];
};

#endif

