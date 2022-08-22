import java.util.ArrayList;

public class TicTacToe {
	public void generateAllGames(TicTacToeBoard board) {
		ArrayList<String> moves=board.legalMoves();
		for (String move : moves) {
			board.makeMove(move);
			if (board.isGameOver()) {
				for (String amove : board.playedMoves()) {
					System.out.print(amove);
				}
				System.out.println();
			} else {
				generateAllGames(new TicTacToeBoard(board));
			}
			board.undoLastMove();
		}
	}

	public static void main(String[] args) {
		TicTacToe t=new TicTacToe();
		TicTacToeBoard b=new TicTacToeBoard();
		t.generateAllGames(b);
	}
}
