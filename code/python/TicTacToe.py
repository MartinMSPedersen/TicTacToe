#!/usr/bin/python3

class TicTacToeBoard():
  def __init__(self):
    self.whoToMove = "X"
    self.is_game_over = False
    self.winner = "" 
    self.lastMove = ""
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