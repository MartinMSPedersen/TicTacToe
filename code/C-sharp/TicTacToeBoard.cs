using System;
using System.Collections.Generic;

namespace TicTacToe
{	
	class TicTacToeBoard
	{
		private char whoToMove;
		private bool is_game_over;
		private char winner;
		private string lastMove;
		private char[,] board;
		private List<string> emptyPlaces;
		private List<string> _playedMoves;

		public TicTacToeBoard()
		{
			whoToMove = 'X';
			is_game_over = false;
			winner = ' ';
			lastMove = "";
			board = new char[3,3];
			for (int row=0; row<3; row++)
				for (int col=0; col<3; col++)
					board[row,col] = '-';
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
			return whoToMove.ToString();
		}

		public void undoLastMove()
		{
			;
		}

	}

	class Program
	{
		static void Main(string[] args)
		{
			TicTacToeBoard t=new TicTacToeBoard();
			Console.WriteLine(t);
		}
	}
}
