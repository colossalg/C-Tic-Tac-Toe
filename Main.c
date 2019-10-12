#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Board.h"
#include "Search.h"



int
main(int argc, char **argv)
{
    printf("Welcome to TicTacToe.\n");
    printf("Would you like to move first? [y/n]: ");

    char resp;
    scanf("%c", &resp);
    
    bool player_is_x = (resp == 'y');

    Board* board = b_init();

    while (true)
    {
        if (b_result(board) != NIL)
            break;

        if (board->x_to_move == player_is_x)
        {
            b_print(board);
            printf("Please enter your move: ");

            int move;
            scanf("%d", &move);
            b_move(board, move);
        } 
        else 
        {
            Node* comp = s_negamax(board);
            b_move(board, comp->best_move);
        }
    }

    b_print(board);
    char* res_str = b_result_str(b_result(board));
    printf("\n%s\n\n", res_str);
    
    free(board);
    free(res_str);

    return 0;
}
