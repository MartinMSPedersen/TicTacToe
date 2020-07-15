#include "TicTacToeBoard.h"
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <forward_list>
#include <string>
#include <random>
#include <vector>
#include <algorithm> 

void generateAllGames(TicTacToeBoard board)
{
	vector<string> moves=board.legalMoves();
	for (vector<string>::iterator it = moves.begin(); it != moves.end(); ++it){
		board.makeMove(*it);
		if (board.isGameOver()) {
			for (auto const& move: board.playedMoves()) cout << move; 
			cout << endl;
		} else {
			generateAllGames(TicTacToeBoard(board));
		}
		board.undoLastMove();
	}
}

int main() 
{
	generateAllGames(TicTacToeBoard());

	return(EXIT_SUCCESS);
}
