source("TicTacToeBoard.R")


makeAllMoves <- function() {
	placeOne <- function(b)
	for (move in b$legalMoves) {
		b <- makeMove(b, move)
		if (b$isGameOver) {
			cat(paste0(b$moves, collapse = ""),"\n")
		} else {
			placeOne(b)
		}
		b <- undoMove(b, move)
	}
	placeOne(TicTacToeBoard())
}


makeAllMoves()	


