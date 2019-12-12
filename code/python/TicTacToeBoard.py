#!/usr/bin/python3

class TicTacToeBoard():
  def __init__(self):
    self.whoToMove = "X"
    self.is_game_over = False
    self.winner = "" 
    self.board = [[0 for x in range(3)] for y in range(3)] 
    self.emptyPlaces = [ "A1", "A2", "A3",
                        "B1", "B2", "B3",
                        "C1", "C2", "C3" ]
    self.playedMoves = []
    for i in range(len(self.board)):
      for j in range(len(self.board[i])):
        self.board[i][j] = "-"

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

  def undoMove(self, move):
    row = ord(move[0:1]) - ord('A')
    col = ord(move[1:2]) - ord('0')
    if (self.board[row][col] == "-"):
       return

    self.board[row][col] = "-"
    if (self.whoToMove == "X"):
      self.whoToMove = "O"
    else:
      self.whoToMove = "X"
    self.emptyPlaces.append(move)
    isGameOver(self)
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

"""
Board = TicTacToeBoard()
Board.print()
Board.makeMove("A1")
Board.print()
Board.makeMove("A3")
Board.print()
Board.makeMove("C3")
Board.print()
Board.makeMove("B2")
Board.print()
Board.makeMove("C1")
Board.print()
Board.makeMove("C2")
Board.print()
Board.makeMove("B1")
Board.print(full = True)
"""
