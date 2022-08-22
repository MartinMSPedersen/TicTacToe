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
	pub fn new() -> TicTacToeBoard {
		TicTacToeBoard {
			is_game_over: false,
			winner: ' ',
			last_move: String::new(),
			_who_to_move: 'X',
			board: ' ',
			empty_places: ' ',
			_played_moves: Vec::new()
		}
	}

    pub fn make_move(&mut self, the_move: String) -> bool {
		true
    }

    pub fn is_game_over(&self) -> bool {
        true
    }

	/*
    pub fn legal_moves(&self) -> Vec(String) {
    }

	pub fn playedMoves(&self) -> Vec(String) {
	}
	*/

	pub fn who_to_move(&self) -> char {
		self._who_to_move
	}

    pub fn undo_last_move(&mut self) {
    }

	pub fn print(&self) {
	}
}


