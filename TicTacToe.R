source("TicTacToeBoard.R")


makeAllGames <- function() {
	placeOne <- function(b) {
		for (move in b$legalMoves) {
			b <- makeMove(b, move)
			if (b$isGameOver) {
				cat(paste0(b$moves, collapse = ""),"\n")
			} else {
				placeOne(b)
			}
			b <- undoMove(b, move)
		}
	}
	placeOne(TicTacToeBoard())
}

makeAllPositions <- function() {
	placeOne <- function(b) {
		for (move in b$legalMoves) {
			b <- makeMove(b, move)
			cat(getPosition(b),"\n")
			if (!b$isGameOver) {
				placeOne(b)
			}
			b <- undoMove(b, move)
		}
	}
	b <- TicTacToeBoard()
	cat(getPosition(b),"\n")
	placeOne(b)
}



#makeAllGames()	
makeAllPositions()	


