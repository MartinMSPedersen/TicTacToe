CXXFLAGS = -Wall -Wunused -Wcast-qual -Wconversion -Woverloaded-virtual  -Wextra -Werror --pedantic-error -finline-functions -ansi -ggdb
CC = g++
OBJS = TicTacToe.o TicTacToeBoard.o 
EXECUTABLES = TicTacToe

TicTacToe: $(OBJS)
	$(CC) -o $@ $(OBJS)

.c.o:
	$(CC) -c $<

clean:
	rm -f $(EXECUTABLES) $(OBJS) core

