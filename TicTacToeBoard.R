makeMove <- function(obj, move) { UseMethod("makeMove") }
isGameOver <- function(obj) { UseMethod("isGameOver") }
undoMove <- function(obj, move) { UseMethod("undoMove") }
getPosition <- function(obj) { UseMethod("getPosition") }

TicTacToeBoard <- function() {
	value <- list(whoToMove = "X", 
		      isGameOver = FALSE, 
		      winner = NA,
		      board = rep("-",9),
		      legalMoves = c("A1","A2","A3","B1","B2","B3","C1","C2","C3"),
		      moves <- list()
		     )
	attr(value, "class") <- "TicTacToeBoard"
	value
}

getPosition.TicTacToeBoard <- function(obj) {
	result <- paste0(obj$board,collapse="")
	result <- gsub("-","001",result,fixed = TRUE)
	result <- gsub("X","010",result,fixed = TRUE)
	result <- gsub("O","100",result,fixed = TRUE)
	result
}

undoMove.TicTacToeBoard <- function(obj, move) {
  row <- switch(substr(move,1,1), A = 0, B = 1, C = 2)
  col <- as.integer(substr(move,2,2))
  pos <- (3 * row + col)
  if (obj$board[[pos]] == "-") return(obj)
  obj$moves <- obj$moves[-length(obj$moves)]
  obj$board[[pos]] <- "-"

  if (obj$whoToMove == "X") {
    obj$whoToMove <-  "O"
  } else {
    obj$whoToMove <- "X"
  }
  obj$legalMoves <- append(obj$legalMoves, move)
  #obj <- isGameOver(obj)
  obj$isGameOver <- FALSE
  obj
}

isGameOver.TicTacToeBoard <- function(obj) {
	if (obj$isGameOver) { return(obj) }
	if (length(obj$legalMoves) == 0) {
		obj$isGameOver <- TRUE
		obj$winner <- "-"
	}
	for (j in 0:2) {
		x1 <- 0; o1 <- 0; x2 <- 0; o2 <- 0
		for (i in 0:2) {
			pos1 <- i+j*3+1
			pos2 <- j+i*3+1
			if (obj$board[[pos1]] == "X") { x1 <- x1 + 1 }
			if (obj$board[[pos1]] == "O") { o1 <- o1 + 1 }
			if (obj$board[[pos2]] == "X") { x2 <- x2 + 1 }
			if (obj$board[[pos2]] == "O") { o2 <- o2 + 1 }
		}
		if (x1== 3 || x2 == 3) {
			obj$isGameOver <- TRUE
			obj$winner <- "X"
		}
		if (o1== 3 || o2 == 3) {
			obj$isGameOver <- TRUE
			obj$winner <- "O"
		}
	}
	if (obj$board[[1]] == obj$board[[5]] && 
	    obj$board[[5]] == obj$board[[9]] &&
	    obj$board[[1]] == "X") {
		obj$isGameOver <- TRUE
		obj$winner <- "X"
	}
	if (obj$board[[1]] == obj$board[[5]] && 
	    obj$board[[5]] == obj$board[[9]] &&
	    obj$board[[1]] == "O") {
		obj$isGameOver <- TRUE
		obj$winner <- "O"
	}
	if (obj$board[[3]] == obj$board[[5]] && 
	    obj$board[[5]] == obj$board[[7]] &&
	    obj$board[[3]] == "X") {
		obj$isGameOver <- TRUE
		obj$winner <- "X"
	}
	if (obj$board[[3]] == obj$board[[5]] && 
	    obj$board[[5]] == obj$board[[7]] &&
	    obj$board[[3]] == "O") {
		obj$isGameOver <- TRUE
		obj$winner <- "O"
	}
	obj
}

print.TicTacToeBoard <- function(obj, full = FALSE) {
	cat(paste0("A ",obj$board[[1]],obj$board[[2]],obj$board[[3]],"\n"))
	cat(paste0("B ",obj$board[[4]],obj$board[[5]],obj$board[[6]],"\n"))
	cat(paste0("C ",obj$board[[7]],obj$board[[8]],obj$board[[9]],"\n"))
	cat(paste0("  123\n"))
	cat("\n")
	if (full) {
	  cat("Moves: ",obj$moves,"\n")
	  cat("Who to move: ",obj$whoToMove,"\n")
	  cat("isGameOver: ",obj$isGameOver,"\n")
	  cat("winner: ",obj$winner,"\n")
	  cat("legalMoves: ",obj$legalMoves,"\n")
	}
}

makeMove.TicTacToeBoard <- function(obj, move) {
	if (obj$isGameOver) return(obj)
	obj$moves <- append(obj$moves, move)
	row <- switch(substr(move,1,1), A = 0, B = 1, C = 2)
	col <- as.integer(substr(move,2,2))
	pos <- (3 * row + col)
	if (obj$board[[pos]] != "-") return(obj)
	if (obj$whoToMove == "X") {
		obj$board[[pos]] <- "X"
		obj$whoToMove <-  "O"
	} else {
		obj$board[[pos]] <- "O"
		obj$whoToMove <- "X"
	}
	obj$legalMoves <- obj$legalMoves[obj$legalMoves != move]
	obj <- isGameOver(obj)
	obj
}

playRandomGames <- function(num = 1) {
  replicate(num, {
    b <- TicTacToeBoard()
    while (b$isGameOver == FALSE) {
      aMove <- sample(b$legalMoves,1)
      b <- makeMove(b, aMove)
    }
    b$moves
  })
}

unittest <- function() {
  b <- TicTacToeBoard()
  print("EMPTY TEST:")
  print(b, full = T)
  cat("\n")
  b <- makeMove(b,"B3")
  b <- makeMove(b,"A3")
  print("B3 TEST:")
  print(b, full = T)
  cat("\n")
  b <- undoMove(b, "B3")
  print("UNDO TEST:")
  print(b, full = T)
  cat("\n")
}


