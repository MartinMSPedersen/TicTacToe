pub struct TicTacToeBoard {
    is_game_over: bool,
    winner:       char,
    last_move:     String,
    _who_to_move:   char,
    board:        char,
    empty_places:  char,
    _played_moves: char,

    /*
    	public:
		TicTacToeBoard();
		friend ostream& operator<< (ostream& o, TicTacToeBoard& tb);
		bool makeMove(string move);
		bool isGameOver();
		void undoLastMove();
		vector<string> legalMoves() const;
		list<string> playedMoves();
		char whoToMove() const;
	private:
		char _whoToMove;
		bool is_game_over;
		char winner;
		string lastMove;
		char board[3][3];
		list<string> emptyPlaces;
		list<string> _playedMoves;
    */

    
}
