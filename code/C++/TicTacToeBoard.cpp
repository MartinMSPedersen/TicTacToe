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
	//board = new char[3][3];
	/*
	for (unsigned int row=0; row<3; row++)
		for (unsigned int col=0; col<3; col++)
			board[row][col] = "-";
	*/
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
	


/*
  def makeMove(self, move):
    if (self.is_game_over):
      return False
    self.playedMoves.append(move)
    row = ord(move[0:1]) - ord('A')
    col = ord(move[1:2]) - ord('1')
    if (self.board[row][col] != "-"):
       return False
    self.board[row][col] = self.whoToMove
    if (self.whoToMove == "X"):
      self.whoToMove = "O"
    else:
      self.whoToMove = "X"
    self.emptyPlaces.remove(move)
    self.lastMove = move
    return self.isGameOver()

  def isGameOver(self):
    if (self.is_game_over == True):
      return True

    if (len(self.emptyPlaces) == 0):
      self.is_game_over == True
      self.winner = "-"
      return True

    for col in range(3):
      Xcount = 0
      Ocount = 0 
      for row in range(3):
        if (self.board[row][col] == "X"):
          Xcount = Xcount + 1
        if (self.board[row][col] == "O"):
          Ocount = Ocount + 1
      if (Xcount == 3):
        self.is_game_over = True
        self.winner = "X"
        return True
      if (Ocount == 3):
        self.is_game_over = True
        self.winner = "O"
        return True

    for row in range(3):
      Xcount = 0
      Ocount = 0 
      for col in range(3):
        if (self.board[row][col] == "X"):
          Xcount = Xcount + 1
        if (self.board[row][col] == "O"):
          Ocount = Ocount + 1
      if (Xcount == 3):
        self.is_game_over = True
        self.winner = "X"
        return True
      if (Ocount == 3):
        self.is_game_over = True
        self.winner = "O"
        return True
       
      if (self.board[0][0] == self.board[1][1] and
          self.board[0][0] == self.board[2][2]):
        if (self.board[0][0] != "-"):
          self.is_game_over = True
          self.winner = self.board[0][0]
          return True

      if (self.board[0][2] == self.board[1][1] and
          self.board[0][2] == self.board[2][0]):
        if (self.board[0][2] != "-"):
          self.is_game_over = True
          self.winner = self.board[0][2]
          return True
    return False

  def undoLastMove(self):
    if (self.lastMove == ""):
      return
    row = ord(self.lastMove[0:1]) - ord('A')
    col = ord(self.lastMove[1:2]) - ord('1')
    self.board[row][col] = "-"
    if (self.whoToMove == "X"):
      self.whoToMove = "O"
    else:
      self.whoToMove = "X"
    self.emptyPlaces.append(self.lastMove)
    self.playedMoves.remove(self.lastMove)
    self.is_game_over = False
    if (len(self.playedMoves) == 0): 
      self.lastMove = ""
    else:
      self.lastMove = self.playedMoves[-1]
    return

  def print(self, full = False):
    print("A ","".join(self.board[0]))
    print("B ","".join(self.board[1]))
    print("C ","".join(self.board[2]))
    print()
    print("   123")
    if (full):
      print()
      print("Played moves: ",self.playedMoves)
      print("Who to move: ",self.whoToMove)
      print("Is game over: ",self.is_game_over)
      if (self.isGameOver): 
        print("Winner: ", self.winner)
      print("Empty places: ",self.emptyPlaces)
      print()
# end of class TicTacTocBoard

def generateAllGames(board):
  for move in list(board.emptyPlaces):
    board.makeMove(move)
    if (board.isGameOver() == True):
      print(board.playedMoves)
    else:
      generateAllGames(board)
    board.undoLastMove()

generateAllGames(TicTacToeBoard())
*/
