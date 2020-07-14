<?php

class TicTacToeBoard {

	private $whoToMove;
	private $is_game_over;
	private $winner;
	private $lastMove;
	private $board;
	public $emptyPlaces;
	public $playedMoves;

	
	function __construct() {
		$this->whoToMove = "X";
		$this->is_game_over = false;
		$this->winner = "";
		$this->lastMove = "";
		$this->board = array(
			array("-","-","-"),
			array("-","-","-"),
			array("-","-","-")
		);
		$this->emptyPlaces = array("A1","A2","A3","B1","B2","B3","C1","C2","C3");
		$this->playedMoved = [];
	}

	function toHTML() {
		;
	}

  function makeMove($move) {
		if ($this->is_game_over == true) return;

		$move=strtoupper($move);
    $row = ord(substr($move,0,1))-ord('A');
    $col = ord(substr($move,1,1))-ord('1');

		if ($this->board[$row][$col] != '-') return;
		$this->board[$row][$col] = $this->whoToMove;
		$this->playedMoves[] = $move;

		if ($this->whoToMove == "X") {
			$this->whoToMove = "O";
		} else {
			$this->whoToMove = "X";
		}
		$this->emptyPlaces = array_diff($this->emptyPlaces, array($move));
		$this->lastMove = $move;
		$this->isGameOver();
	}

	function isGameOver() {
		if ($this->is_game_over == true) return true;

		for ($col = 0; $col < 3; $col++) {
			$Xcount = 0;
			$Ocount = 0;
			for ($row = 0; $row < 3; $row++) {
				if ($this->board[row][col] == "X")
					$Xcount++;
				if ($this->board[row][col] == "O")
					$Ocount++;
			}
      if ($Xcount == 3) {
				$this->is_game_over = true;
				$this->winner = "X";
				return true;
			}
      if ($Ocount == 3) {
				$this->is_game_over = true;
				$this->winner = "O";
				return true;
			}
		}

		for ($row = 0; $row < 3; $row++) {
			$Xcount = 0;
			$Ocount = 0;
			for ($col = 0; $col < 3; $col++) {
				if ($this->board[row][col] == "X")
					$Xcount++;
				if ($this->board[row][col] == "O")
					$Ocount++;
			}
      if ($Xcount == 3) {
				$this->is_game_over = true;
				$this->winner = "X";
				return true;
			}
      if ($Ocount == 3) {
				$this->is_game_over = true;
				$this->winner = "O";
				return true;
			}
		}

		if ($this->board[0][0] == $this->board[1][1] && $this->board[1][1] == $this->board[2][2] && $this->board[0][0] != "-") {
			$this->is_game_over = true;
			$this->winner = $this->board[0][0];
			return true;
		}
		if ($this->board[0][2] == $this->board[1][1] && $this->board[1][1] == $this->board[2][0] && $this->board[0][2] != "-") {
			$this->is_game_over = true;
			$this->winner = $this->board[0][2];
			return true;
		}
		if (count($this->emptyPlaces) == 0) {
			$this->is_game_over = true;
			$this->winner = "-";
			return true;
		}
		return false;
	}

	function undoLastMove() {
		if ($this->lastMove == "") return;

    $row = ord(substr($this->lastMove,0,1))-ord('A');
    $col = ord(substr($this->lastMove,1,1))-ord('1');
		$this->board[row][col] = "-";

		if ($this->whoToMove == "X") {
			$this->whoToMove = "O";
		} else {
			$this->whoToMove = "X";
		}
		$this->emptyPlaces[] = $this->lastMove;
		array_pop($this->playedMoves);
		$this->is_game_over = false;
		if (count($this->playedMoves) == 0) {
			$this->lastMove = [];
		}
		$this->lastMove = end($this->playedMoves);
		reset($this->playedMoves);
	}

	function toText() {
		$result="";
		$result = $result . "A ";
		foreach ($this->board[0] as $piece) {
			$result = $result . $piece;
		}
		$result = $result . "\n";
		$result = $result . "B ";
		foreach ($this->board[1] as $piece) {
			$result = $result . $piece;
		}
		$result = $result . "\n";
		$result = $result . "C ";
		foreach ($this->board[2] as $piece) {
			$result = $result . $piece;
		}
		$result = $result . "\n";
		$result = $result . "  123";
		$result = $result . "\n";
		echo $result;
		/*
    if full:
      print()
      print("Played moves: ",self.playedMoves)
      print("Who to move: ",self.whoToMove)
      print("Is game over: ",self.is_game_over)
      if self.isGameOver: 
        print("Winner: ", self.winner)
      print("Empty places: ",self.emptyPlaces)
      print()
		*/
	}
}

?>
