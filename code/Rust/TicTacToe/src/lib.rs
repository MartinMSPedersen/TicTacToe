pub struct TicTacToeBoard {
    is_game_over:  bool,
    winner:        char,
    last_move:     String,
    _who_to_move:  char,
    board:         char,
    empty_places:  char,
    _played_moves: Vec<String>,
    /*
    	public:
		TicTacToeBoard();
		friend ostream& operator<< (ostream& o, TicTacToeBoard& tb);
		void undoLastMove();
		vector<string> legalMoves() const;
		list<string> playedMoves();
		char whoToMove() const;
    */
}

impl TicTacToeBoard {
    pub fn make_move(&mut self, move: String) -> bool {
    }

    pub fn is_game_over(&self) -> bool {
        true
    }

    pub fn legal_moves(&self) -> Vec(String) {
    }

    pub fn undo_last_move(&mut self) {
    }
}


