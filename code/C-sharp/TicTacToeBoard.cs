using System;
using System.Collections.Generic;

namespace TicTacToe
{	
	class TicTacToeBoard
	{
		private char _whoToMove;
		private bool is_game_over;
		private char winner;
		private string lastMove;
		private char[,] board;
		private List<string> emptyPlaces;
		private List<string> _playedMoves;

		public TicTacToeBoard()
		{
			_playedMoves=new List<string>();
			_whoToMove = 'X';
			is_game_over = false;
			winner = ' ';
			lastMove = "";
			board = new char[3,3];
			for (int row=0; row<3; row++)
				for (int col=0; col<3; col++)
					board[row,col] = '-';
			emptyPlaces=new List<string>();
			emptyPlaces.Add("A1");
			emptyPlaces.Add("A2");
			emptyPlaces.Add("A3");
			emptyPlaces.Add("B1");
			emptyPlaces.Add("B2");
			emptyPlaces.Add("B3");
			emptyPlaces.Add("C1");
			emptyPlaces.Add("C2");
			emptyPlaces.Add("C3");
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
	
		public bool makeMove(string move) 
		{
			int row;
			int col;

			if (is_game_over) return false;
			move=move.ToUpper();
			row=char.Parse(move.Substring(0,1))-'A';
			col=char.Parse(move.Substring(1,1))-'1';
			if (board[row,col] != '-') return false;
			_playedMoves.Add(new string(move));
			board[row,col]=_whoToMove;
			if (_whoToMove == 'X') {
				_whoToMove='O';
			} else {
				_whoToMove='X';
			}
			emptyPlaces.Remove(move);
			lastMove=move;
			return isGameOver();
		}

		public override string ToString()
		{
			string result=new string("");
		
			result += "  123\n";
			result += "A "; 
			result += board[0,0];
			result += board[0,1];
			result += board[0,2];
			result += " A\n";
			result += "B "; 
			result += board[1,0];
			result += board[1,1];
			result += board[1,2];
			result += " B\n";
			result += "C "; 
			result += board[2,0];
			result += board[2,1];
			result += board[2,2];
			result += " C\n";
			result += "  123";
			return result;
		}

		public char whoToMove() { return _whoToMove; }

		public void undoLastMove()
		{
			int row, col;

			if (lastMove == " ") return;
			row=char.Parse(lastMove.Substring(0,1))-'A';
			col=char.Parse(lastMove.Substring(1,1))-'1';
			board[row,col]='-';
			if (_whoToMove == 'X') {
				_whoToMove='O';
			} else {
				_whoToMove='X';
			}
			emptyPlaces.Add(lastMove);
			_playedMoves.Remove(lastMove);
			if (_playedMoves.Count == 0) {
				lastMove=" ";
			} else {
				lastMove=_playedMoves[_playedMoves.Count-1];
			}
			is_game_over=false;
		}

		public List<string> legalMoves() 
		{
			List<string> result=new List<string>(emptyPlaces);
			return result;
		}

		public List<string> playedMoves()
		{
			return _playedMoves;
		}

		public int eval()
		{
			if (isGameOver()) {
				if (winner == 'X') return  100;
				if (winner == 'O') return -100;
			}
			return 0;
		}

		public bool isGameOver()
		{
			int Xcount;
			int Ocount;

			if (is_game_over) return true;
			if (emptyPlaces.Count == 0) {
				is_game_over=true;
				winner=' ';
				return true;
			}
			for (int col=0; col<3; col++) {
				Xcount=0;
				Ocount=0;
				for (int row=0; row<3; row++) {
					if (board[row,col] == 'X') Xcount++;
					if (board[row,col] == 'O') Ocount++;
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
					if (board[row,col] == 'X') Xcount++;
					if (board[row,col] == 'O') Ocount++;
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
			if (board[0,0] == board[1,1] &&
			    board[0,0] == board[2,2] &&
			    board[0,0] != '-') {
			  is_game_over=true;
			  winner=board[0,0];
			  return true;
			}
			if (board[0,2] == board[1,1] &&
			    board[0,2] == board[2,0] &&
			    board[0,2] != '-') {
			  is_game_over=true;
			  winner=board[0,2];
			  return true;
			}
			return false;
		}
	}

}
