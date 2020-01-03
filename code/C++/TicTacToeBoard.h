#ifndef _TICTACTOEBOARD_H_
#define _TICTACTOEBOARD_H_

#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

class TicTacToeBoard 
{
	public:
		TicTacToeBoard();
		friend ostream& operator<< (ostream& o, TicTacToeBoard& tb);
		bool makeMove(string move);
		bool isGameOver();
		void undoLastMove();
		vector<string> legalMoves() const;
		list<string> playedMoves();
	private:
		char whoToMove;
		bool is_game_over;
		char winner;
		string lastMove;
		char board[3][3];
		list<string> emptyPlaces;
		list<string> _playedMoves;
};

#endif

