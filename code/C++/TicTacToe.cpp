#include "TicTacToeBoard.h"
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <forward_list>
#include <string>
#include <random>
#include <vector>
#include <algorithm> 

void playARandomGame() {
	random_device seed;
	mt19937 engine(seed());

	TicTacToeBoard t;
	vector<string> moves;
	
	while (!t.isGameOver()) {
		moves=t.legalMoves();
		uniform_int_distribution<long unsigned int> choose(0, moves.size()-1);
		t.makeMove(moves[choose(engine)]);
	}
	for (auto const& move: t.playedMoves()) {
		cout << move;
	}
	cout << endl;
}

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

int MinMax(TicTacToeBoard board)
{
	bool maxPlayer;
	int bestValue;
	vector<string> moves;

	if (board.isGameOver()) {
		return board.eval() ;
	}
	moves=board.legalMoves();
	if (board.whoToMove() == 'X') {
		maxPlayer=true;
		bestValue=-1000;
	} else {
		maxPlayer=false;
		bestValue=1000;
	}
	std::random_shuffle(moves.begin(),moves.end());
	for (vector<string>::iterator it=moves.begin(); it!=moves.end(); ++it) {
 		board.makeMove(*it);
		if (maxPlayer) {
			bestValue=max(bestValue,MinMax(board));
		} else {
			bestValue=min(bestValue,MinMax(board));
		}
		board.undoLastMove();
	}
	return bestValue;
}

int main() 
{
  generateAllGames(TicTacToeBoard());

  return(EXIT_SUCCESS);
}
