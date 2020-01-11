using System;
using System.Collections.Generic;

namespace TicTacToe
{	
	class TicTacToe
	{
		public void generateAllGames(TicTacToeBoard board) {
			List<string> moves=board.legalMoves();
			foreach (string move in moves) {
				board.makeMove(move);
				if (board.isGameOver()) {
					board.playedMoves().ForEach(Console.Write);
					Console.WriteLine();
				} else {
					generateAllGames(new TicTacToeBoard(board));
				}
				board.undoLastMove();
			}
		}

	}

	class Program
	{
		static void Main(string[] args)
		{
			TicTacToe t=new TicTacToe();
			TicTacToeBoard b=new TicTacToeBoard();
			t.generateAllGames(b);
		}
	}
}
