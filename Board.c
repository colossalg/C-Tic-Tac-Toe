#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Board.h"



int winning_combos_len = 8;
int winning_combos[] = {
    448, 56, 7,     // Rows  b111000000 b000111000 b000000111
    292, 146, 73,   // Cols  b100100100 b010010010 b001001001
    273, 84         // Diags b100010001 b001010100
};



Board*
b_init(void)
{
    Board* new_board = malloc(sizeof(Board));
    if (new_board == NULL)
    {
        perror(__func__);
        exit(EXIT_FAILURE);
    }

    new_board->x_pieces  = 0;     // b 000 000 000
    new_board->o_pieces  = 0;     // b 000 000 000
    new_board->empty     = 511;   // b 111 111 111
    new_board->x_to_move = true;

    return new_board;
}



Board*
b_clone(Board* board)
{
    Board* clone = malloc(sizeof(Board));
    if (clone == NULL) 
    {
        perror(__func__);
        exit(EXIT_FAILURE);
    }
    clone->x_pieces  = board->x_pieces;
    clone->o_pieces  = board->o_pieces;
    clone->empty     = board->empty;
    clone->x_to_move = board->x_to_move;

    return clone;
}



void
b_move(Board* board, int move)
{
    if (move < 0 || move >= 9) 
    {
        fprintf(stderr, "Error: move must be an integer between 0 and 8"
                ": recieved %d.\n", move);
        exit(EXIT_FAILURE);
    }

    if (board->x_to_move)
        board->x_pieces |= (1 << move);
    else
        board->o_pieces |= (1 << move);

    board->empty &= (~(1 << move));
    board->x_to_move = !(board->x_to_move);
}



bool
b_move_validate(Board* board, int move)
{
    return ((board->empty & (1 << move)) != 0);
}



void
b_print(Board* board)
{
    for (int i = 0; i < 9; ++i)
    {
        if (i % 3 == 0)
            printf("\n");

        /*
            Only one of the following should ever execute but
            it helps with debugging if we check for all.
        */
        if ((board->x_pieces & (1 << i)) != 0)
            printf("X");
        if ((board->o_pieces & (1 << i)) != 0)
            printf("O");
        if ((board->empty & (1 << i)) != 0)
            printf(".");
    }

    printf("\n");
}



Result
b_result(Board* board)
{
    for (int i = 0; i < winning_combos_len; ++i)
    {
        int combo = winning_combos[i];

        if ((board->x_pieces & combo) == combo)
            return X_WIN;
        if ((board->o_pieces & combo) == combo)
            return O_WIN;
    }

    return (board->empty == 0 ? DRAW : NIL);
}



char*
b_result_str(Result res)
{
    char* res_str = NULL;    
    
    switch (res)
    {
        case X_WIN :
            res_str = strdup("The winner is X!");
            break;
        case O_WIN :
            res_str = strdup("The winner is O!");
            break;
        case DRAW :
            res_str = strdup("The game is a draw.");
            break;
        default :
            break;
    } 

    return res_str;
}

