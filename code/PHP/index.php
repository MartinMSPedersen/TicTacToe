<?php
require("TicTacToeBoard.php");

function generateAllGames($board) {
	global $count;
	foreach ($board->get_emptyPlaces() as $move) {
		$board->makeMove($move);
		if ($board->isGameOver() == true) {
			$count++;
			foreach ($board->get_playedMoves() as $move) {
				echo $move;
			}
			echo "\n";
			$board->toText();
		} else {
			generateAllGames($board);
		}
		$board->undoLastMove();
	}
}

$count=0;
$a_board = new TicTacToeBoard;
echo "<pre>";
generateAllGames($a_board);
echo "</pre>";
echo "<H1>";
echo $count;
echo "</H1>";

?>
