import java.util.ArrayList;

public class TicTacToeBoard {
	private char _whoToMove;
	private boolean is_game_over;
	private char winner;
	private String lastMove;
	private char[][] board;
	private ArrayList<String> emptyPlaces;
	private ArrayList<String> _playedMoves;

	public TicTacToeBoard()
	{
		_playedMoves=new ArrayList<String>();
		_whoToMove = 'X';
		is_game_over = false;
		winner = ' ';
		lastMove = "";
		board = new char[3][3];
		for (int row=0; row<3; row++)
			for (int col=0; col<3; col++)
				board[row][col] = '-';
		emptyPlaces=new ArrayList<String>();
		emptyPlaces.add("A1");
		emptyPlaces.add("A2");
		emptyPlaces.add("A3");
		emptyPlaces.add("B1");
		emptyPlaces.add("B2");
		emptyPlaces.add("B3");
		emptyPlaces.add("C1");
		emptyPlaces.add("C2");
		emptyPlaces.add("C3");
	}

	public TicTacToeBoard(TicTacToeBoard t2) {
		_whoToMove=t2._whoToMove;
		is_game_over=t2.is_game_over;
		winner=t2.winner;
		lastMove=t2.lastMove;
		board=t2.board;
		emptyPlaces=t2.emptyPlaces;
		_playedMoves=t2._playedMoves;
	}

	public boolean makeMove(String move) 
	{
		int row;
		int col;

		if (is_game_over) return false;
		move=move.toUpperCase();
		row=move.charAt(0) - 'A';
		col=move.charAt(1) - '1';
		if (board[row][col] != '-') return false;
		_playedMoves.add(move);
		board[row][col]=_whoToMove;
		if (_whoToMove == 'X') {
			_whoToMove='O';
		} else {
			_whoToMove='X';
		}
		emptyPlaces.remove(move);
		lastMove=move;
		return isGameOver();
	}

	@Override
		public String toString()
		{
			String result="";

			result += "  123\n";
			result += "A "; 
			result += board[0][0];
			result += board[0][1];
			result += board[0][2];
			result += " A\n";
			result += "B "; 
			result += board[1][0];
			result += board[1][1];
			result += board[1][2];
			result += " B\n";
			result += "C "; 
			result += board[2][0];
			result += board[2][1];
			result += board[2][2];
			result += " C\n";
			result += "  123";
			return result;
		}

	public char whoToMove() { return _whoToMove; }

	public void undoLastMove()
	{
		int row, col;

		if (lastMove == " ") return;
		row=lastMove.charAt(0) - 'A';
		col=lastMove.charAt(1) - '1';
		board[row][col]='-';
		if (_whoToMove == 'X') {
			_whoToMove='O';
		} else {
			_whoToMove='X';
		}
		emptyPlaces.add(lastMove);
		_playedMoves.remove(lastMove);
		if (_playedMoves.size() == 0) {
			lastMove=" ";
		} else {
			lastMove=_playedMoves.get(_playedMoves.size()-1);
		}
		is_game_over=false;
	}

	public ArrayList<String> legalMoves() 
	{
		ArrayList<String> result=new ArrayList<String>(emptyPlaces);
		return result;
	}

	public ArrayList<String> playedMoves()
	{
		return _playedMoves;
	}

	public boolean isGameOver()
	{
		int Xcount;
		int Ocount;

		if (is_game_over) return true;
		if (emptyPlaces.size() == 0) {
			is_game_over=true;
			winner=' ';
			return true;
		}
		for (int col=0; col<3; col++) {
			Xcount=0;
			Ocount=0;
			for (int row=0; row<3; row++) {
				if (board[row][col] == 'X') Xcount++;
				if (board[row][col] == 'O') Ocount++;
			}
			if (Xcount == 3) {
				is_game_over=true;
				winner = 'X';
				return true;
			}
			if (Ocount == 3) {
				is_game_over=true;
				winner = 'O';
				return true;
			}
		}
		for (int row=0; row<3; row++) {
			Xcount=0;
			Ocount=0;
			for (int col=0; col<3; col++) {
				if (board[row][col] == 'X') Xcount++;
				if (board[row][col] == 'O') Ocount++;
			}
			if (Xcount == 3) {
				is_game_over=true;
				winner = 'X';
				return true;
			}
			if (Ocount == 3) {
				is_game_over=true;
				winner = 'O';
				return true;
			}
		}
		if (board[0][0] == board[1][1] &&
				board[0][0] == board[2][2] &&
				board[0][0] != '-') {
			is_game_over=true;
			winner=board[0][0];
			return true;
		}
		if (board[0][2] == board[1][1] &&
				board[0][2] == board[2][0] &&
				board[0][2] != '-') {
			is_game_over=true;
			winner=board[0][2];
			return true;
		}
		return false;
	}
}
