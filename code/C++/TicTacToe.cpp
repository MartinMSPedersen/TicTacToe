#include "TicTacToeBoard.h"
#include <cstdlib>
#include <iostream>
#include <iterator>

void generateAllGames(TicTacToeBoard board)
{
  list<string> moves;
  list<string>::iterator it;

  moves=board.emptyPlaces;

  for (it=moves.begin(); it != moves.end(); ++it) {
    board.makeMove(*it);
    if (board.isGameOver()) {
      copy(board.playedMoves.begin(),
           board.playedMoves.end(),
           ostream_iterator<string>(cout));
      cout << endl;
    } else {
      generateAllGames(board);
    }
    board.undoLastMove();
  }
}

int main() 
{
  generateAllGames(TicTacToeBoard());

  return(EXIT_SUCCESS);
}
