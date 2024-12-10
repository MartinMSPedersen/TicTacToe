const std = @import("std");

const TicTacToeBoard = struct {
    whoToMove: [1]u8,
    isGameOver: bool,
    winner: ?[1]u8,
    board: [9]u8,
    legalMoves: [9]?[2]u8,
    moves: std.ArrayList([2]u8),
};

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

pub fn main() !void {}
