#!/usr/bin/python3

from TicTacToeBoard import *

def generateAllGames(board):
  for move in list(board.emptyPlaces):
    board.makeMove(move)
    if board.isGameOver() == True:
      for move in board.playedMoves:
        print(move, end="")
      print()
    else:
      generateAllGames(board)
    board.undoLastMove()

if __name__ == '__main__':
	generateAllGames(TicTacToeBoard())
