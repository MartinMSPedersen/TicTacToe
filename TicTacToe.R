source("TicTacToeBoard.R")


makeAllMoves <- function() {
	placeOne <- function(b)
	for (move in b$legalMoves) {
		b <- makeMove(b, move)
		if (!b$isGameOver) {
			placeOne(b)
		} else {
			cat(paste0(b$moves, collapse = ""),"\n")
		}
		b <- undoMove(b, move)
	}
	placeOne(TicTacToeBoard())
}


makeAllMoves()	


