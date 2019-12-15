CXXFLAGS = -std=c++11 -Wunused -Wcast-qual -Wconversion -Woverloaded-virtual  -Werror -finline-functions -ggdb 
CC = g++ 
OBJS = TicTacToe.o TicTacToeBoard.o 
EXECUTABLES = TicTacToe

TicTacToe: $(OBJS)
	$(CC) -o $@ $(OBJS)

.c.o:
	$(CC) -c $<

clean:
	rm -f $(EXECUTABLES) $(OBJS) core

