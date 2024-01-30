MAIN_OBJECTS = TicTacToeBoard.java TicTacToe.java
CLASSPATH = /usr/share/java/junit4.jar:.

JAVAC = ${PATH_TO_JAVAC}javac
JAVA = ${PATH_TO_JAVAC}java

JAVAC_FLAGS =  -Xmaxerrs 10 -Werror -Xlint:all -cp ${CLASSPATH}

all:	TicTacToe

TicTacToe: $(MAIN_OBJECTS) 
	$(JAVAC) $(JAVAC_FLAGS) $(MAIN_OBJECTS) 

.PHONY:	clean

clean:
	rm *.class
