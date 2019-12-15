#include "TicTacToeBoard.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>
#include <cstring>
#include <algorithm> 

using namespace std;

TicTacToeBoard::TicTacToeBoard()
{
	whoToMove = 'X';
	is_game_over = false;
	winner = ' ';
	lastMove = ' ';
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

        result+="  123\n";
        result+="A ";
	result+=tb.board[0][0];
	result+=tb.board[0][1];
	result+=tb.board[0][2];
	result+=" A";
        result+="\nB ";
	result+=tb.board[1][0];
	result+=tb.board[1][1];
	result+=tb.board[1][2];
	result+=" B";
        result+="\nC ";
	result+=tb.board[2][0];
	result+=tb.board[2][1];
	result+=tb.board[2][2];
	result+=" C";
        result+="\n  123";
	return o << result;
}

bool TicTacToeBoard::isGameOver() 
{
  unsigned char Xcount;
  unsigned char Ocount;

  if (is_game_over) return true;
  if (emptyPlaces.size() == 0) {
    is_game_over=true;
    winner='-';
    return true;
  }
  for (unsigned char col=0; col<3; col++) {
    Xcount=0;
    Ocount=0;
    for (unsigned char row=0; row<3; row++) {
      if (board[row][col] == 'X') Xcount++;
      if (board[row][col] == 'O') Ocount++;
    }
    if (Xcount == 3) {
      is_game_over=true;
      winner='X';
      return true;
    }
    if (Ocount == 3) {
      is_game_over=true;
      winner='O';
      return true;
    }
  }
  for (unsigned char row=0; row<3; row++) {
    Xcount=0;
    Ocount=0;
    for (unsigned char col=0; col<3; col++) {
      if (board[row][col] == 'X') Xcount++;
      if (board[row][col] == 'O') Ocount++;
    }
    if (Xcount == 3) {
      is_game_over=true;
      winner='X';
      return true;
    }
    if (Ocount == 3) {
      is_game_over=true;
      winner='O';
      return true;
    }
  }
  if (board[0][0] == board[1][1] &&
      board[0][0] == board[2][2] &&
      board[0][0] != '-') {
    is_game_over=true;
    winner=board[0][0];
    return true;
  }
  if (board[0][2] == board[1][1] &&
      board[0][2] == board[2][0] &&
      board[0][2] != '-') {
    is_game_over=true;
    winner=board[0][2];
    return true;
  }
  return false;
}

void TicTacToeBoard::undoLastMove() {
  int row,col;

  if (lastMove == " ") return;
  row=lastMove.at(0)-'A';
  col=lastMove.at(1)-'1';
  board[row][col]='-';
  if (whoToMove=='X') {
    whoToMove='O';
  } else {
    whoToMove='X';
  }
  emptyPlaces.push_back(lastMove);
  _playedMoves.remove(lastMove);
  if (_playedMoves.size()==0) {
    lastMove=' ';
  } else {
    lastMove=*(--_playedMoves.end());
  }
}

bool TicTacToeBoard::makeMove(string move) 
{
  int row;
  int col;

  transform(move.begin(), move.end(), move.begin(), ::tolower); 
  if (is_game_over) return false;
  row=move.at(0)-'A';
  col=move.at(1)-'1';
  if (board[row][col] != '-') return false;
  _playedMoves.push_back(move);
  board[row][col]=whoToMove;
  if (whoToMove == 'X') {
    whoToMove='O';
  } else {
    whoToMove='X';
  }
  emptyPlaces.remove(move);
  lastMove=move;
  return isGameOver();
}

list<string> TicTacToeBoard::legalMoves() const
{
  list<string> result;
  list<string>::iterator it;

  for (auto const& it : emptyPlaces) {
    result.push_back(it);
  }
  return result;
}

list<string> TicTacToeBoard::playedMoves()
{
  return _playedMoves;
}
