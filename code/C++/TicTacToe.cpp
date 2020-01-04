#include "TicTacToeBoard.h"
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <forward_list>
#include <string>
#include <random>
#include <vector>

random_device seed;
mt19937 engine(seed());

void playARandomGame() {
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


int main() 
{
  generateAllGames(TicTacToeBoard());

  return(EXIT_SUCCESS);
}
