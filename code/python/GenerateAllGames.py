#!/usr/bin/python3

from TicTacToeBoard import *

def generateAllGames(board):
  for move in list(board.emptyPlaces):
    board.makeMove(move)
    if board.isGameOver() == True:
      print(board.playedMoves)
    else:
      generateAllGames(board)
    board.undoLastMove()

generateAllGames(TicTacToeBoard())
