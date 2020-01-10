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
			
			

	}

	class Program
	{
		static void Main(string[] args)
		{
			TicTacToeBoard t=new TicTacToeBoard();
			Console.WriteLine(t);
			t.legalMoves().ForEach(Console.WriteLine);
		}
	}
}
