#include "TicTacToeBoard.h"
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <forward_list>
#include <string>

void generateAllGames(TicTacToeBoard board)
{
  forward_list<TicTacToeBoard> boards;
  TicTacToeBoard b;
  list<string> moves;

  boards.push_front(board);

  while (!boards.empty() > 0) {
    b=boards.front();
    moves=b.legalMoves();
    for (list<string>::iterator it = moves.begin(); it != moves.end(); ++it){
      b.makeMove(*it);
      if (b.isGameOver()) {
        copy(board.playedMoves().begin(),
             board.playedMoves().end(),
             ostream_iterator<string>(cout));
        cout << endl;
      } else {
        boards.push_front(b);
      }
      b.undoLastMove();
    }
  }
}

int main() 
{
  generateAllGames(TicTacToeBoard());

  return(EXIT_SUCCESS);
}
