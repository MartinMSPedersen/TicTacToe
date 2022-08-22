CXXFLAGS = -std=c++11 -Wunused -Wcast-qual -Wconversion -Woverloaded-virtual  -Werror -finline-functions -ggdb 
CC = g++ 
EXECUTABLES = TicTacToe
OBJS = TicTacToeBoard.cpp TicTacToe.cpp


TicTacToe: $(OBJS)
	$(CC) -o $@ $(OBJS) && strip $@

clean:
	rm -f $(EXECUTABLES)

