library(magrittr)

source("TicTacToeBoard.R")

makeAllGames <- function(output = FALSE) {
	result <- vector("character", 260000)
	idx <- 1
	placeOne <- function(b) {
		for (move in b$legalMoves) {
			b <- makeMove(b, move)
			if (b$isGameOver) {
				if (output) {
					cat(paste0(b$moves, collapse = ""),"\n")
				}
				result[idx] <<- paste0(b$moves, collapse = "")
				idx <<- idx + 1
			} else {
				placeOne(b)
			}
			b <- undoMove(b, move)
		}
	}
	placeOne(TicTacToeBoard())
	result[nchar(result) != 0]
}

makeAllPositions <- function(output = FALSE) {
	result <- vector("character", 6e5)
	b <- TicTacToeBoard()
        result[1] <- getPosition(b)	
	idx <- 2
	if (output) {
		cat(getPosition(b),"\n")
	}

	placeOne <- function(b) {
		for (move in b$legalMoves) {
			b <- makeMove(b, move)
			if (output) {
				cat(getPosition(b),"\n")
			}
			result[idx] <<- getPosition(b)
			idx <<- idx + 1
			if (!b$isGameOver) {
				placeOne(b)
			}
			b <- undoMove(b, move)
		}
	}
	placeOne(b)
	result <- unique(result)
	result[nchar(result) != 0]
}

games <- makeAllGames(T)	
positions <- makeAllPositions(T)
	



