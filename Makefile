CC 		= cc -std=c99
CFLAGS 	= -Wall -Werror -pedantic --debug

SRC		= Main.c Board.c Search.c
INC		= Board.h Search.h

PROJ	= TicTacToe

$(PROJ) : $(SRC) $(INC)
	$(CC) $(CFLAGS) $(SRC) -o $(PROJ)
