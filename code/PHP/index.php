<?php
require("TicTacToeBoard.php");

function generateAllGames($board) {
	foreach ($board->emptyPlaces as $move) {
		$board->makeMove($move);
		if ($board->isGameOver() == true) {
			echo "<pre>";
			foreach ($board->playedMoves as $move) {
				echo $move;
			}
			echo "\n";
			$board->toText();
			echo "</pre>";
		} else {
			generateAllGames($board);
		}
		$board->undoLastMove();
	}
}

$a_board = new TicTacToeBoard;
generateAllGames($a_board);

?>
