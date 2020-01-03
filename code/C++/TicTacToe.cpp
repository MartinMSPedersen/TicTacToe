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


void generateAllGames(TicTacToeBoard board)
{
  forward_list<TicTacToeBoard> boards;
  TicTacToeBoard b;
  vector<string> moves;

  boards.push_front(board);

  while (!boards.empty() > 0) {
    b=boards.front();
    moves=b.legalMoves();
    for (vector<string>::iterator it = moves.begin(); it != moves.end(); ++it){
      b.makeMove(*it);
      if (b.isGameOver()) {
	for (auto const& move: b.playedMoves()) {
		cout << move;
	}
	cout << endl;
/*
        copy(board.playedMoves().begin(),
             board.playedMoves().end(),
             ostream_iterator<string>(cout));
        cout << endl;
*/
      } else {
        boards.push_front(b);
      }
      b.undoLastMove();
    }
  }
}

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

int main() 
{
  while (1) {
	  playARandomGame();
  }
  /* 
    generateAllGames(TicTacToeBoard());
  */


  return(EXIT_SUCCESS);
}
