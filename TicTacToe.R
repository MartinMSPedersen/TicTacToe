setwd("/home/bruger1/tictactoe")
source("TicTacToeBoard.R")

b <- TicTacToeBoard()
for (move1 in b$legalMoves) {
  b <- makeMove(b, move1)
  for (move2 in b$legalMoves) {
    b <- makeMove(b, move2)
    for (move3 in b$legalMoves) {
      b <- makeMove(b, move3)
      for (move4 in b$legalMoves) {
        b <- makeMove(b, move4)
        for (move5 in b$legalMoves) {
          b <- makeMove(b, move5)
          if (b$isGameOver) {
            print(b)
            cat(b$moves)
            cat("\n")
            b <- undoMove(b,move5)
            next
          }
          for (move6 in b$legalMoves) {
            b <- makeMove(b, move6)
            if (b$isGameOver) {
              cat(b$moves)
              cat("\n")
              b <- undoMove(b,move6)
              next
            }
            for (move7 in b$legalMoves) {
              cat("move7 = ",move7,", class=",class(move7),"\n")
              b <- makeMove(b, move7)
              if (b$isGameOver) {
                print(b, full = T)
                b <- undoMove(b,move7)
                next
              }
              for (move8 in b$legalMoves) {
                b <- makeMove(b, move8)
                if (b$isGameOver) {
                  cat(b$moves)
                  cat("\n")
                  b <- undoMove(b,move8)
                  next
                }
                for (move9 in b$legalMoves) {
                  b <- makeMove(b, move9)
                  cat(b$moves)
                  cat("\n")
                  b <- undoMove(b,move5)
                } # move 9
              } # move 8
            } # move 7
          } # move 6
        } # move 5
      } # move 4
    } # move 3
  } # move 2
} # move 1
      
