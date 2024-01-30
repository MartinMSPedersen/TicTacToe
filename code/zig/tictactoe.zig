const std = @import("std");

const TicTacToeBoard = struct {
    whoToMove: [1]u8,
    isGameOver: bool,
    winner: ?[1]u8,
    board: [9]u8,
    legalMoves: [9]?[2]u8,
    moves: std.ArrayList([2]u8),
};

//pub fn initTicTacToeBoard(allocator: *std.mem.Allocator) !TicTacToeBoard {
//    var board: TicTacToeBoard = TicTacToeBoard{
//        .whoToMove = "X",
//        .isGameOver = false,
//        .winner = null,
//        .board = "---------",
//        .legalMoves = [][2]u8{ "A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3" } **null**,
//        .moves = std.ArrayList([2]u8).init(allocator),
//    };
//    return board;
//}

//pub fn makeMove(board: *TicTacToeBoard, move: [2]u8) !void {
//    // Implementation of making a move, modifying the board struct in place
//
//}

pub fn isGameOver(board: *TicTacToeBoard) void {
    // Check rows and columns
    for (std.math.range(0, 3)) |row| {
        if (board.board[row * 3] == board.board[row * 3 + 1] and board.board[row * 3 + 1] == board.board[row * 3 + 2] and board.board[row * 3] != '-') {
            board.isGameOver = true;
            board.winner = board.board[row * 3];
            return;
        }

        if (board.board[row] == board.board[row + 3] and board.board[row + 3] == board.board[row + 6] and board.board[row] != '-') {
            board.isGameOver = true;
            board.winner = board.board[row];
            return;
        }
    }

    // Check diagonals
    //if ((board.board[0] == board.board[4] and board.board[4] == board.board[8]) or (board.board[2] == board.board[4] and board.board[4] == board.board[6])) and (board.board[4] != '-') {
    //    board.isGameOver = true;
    //    board.winner = board.board[4];
    //    return;
    //}

    // Check for a draw
    var isDraw = true;
    for (board.board) |cell| {
        if (cell == '-') {
            isDraw = false;
            break;
        }
    }

    if (isDraw) {
        board.isGameOver = true;
        board.winner = null; // No winner in case of a draw
    }
}

pub fn main() !void {
    //var board = try initTicTacToeBoard(allocator);
    // Use board, make moves, check for game over, etc.
}
