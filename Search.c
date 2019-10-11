#include <stdio.h>
#include <stdlib.h>

#include "Board.h"
#include "Search.h"



Node*
s_minimax(Board* board)
{
    // TODO
    return NULL;
}



Node*
s_negamax(Board* board)
{
    int mod = (board->x_to_move ? 1 : -1);
    
    Node* best = malloc(sizeof(Node));
    if (best == NULL)
    {
        perror(__func__);
        exit(EXIT_FAILURE);
    }
    best->best_move  = -1;
    best->best_score = -1 * mod;

    /* 
     * Check if the game is over and return the result if it is. 
     */
    if (b_result(board) != NIL)
    {
        best->best_score = b_result(board);
        return best;
    }

    for (int i = 0; i < 9; ++i)
    {
        if (b_move_validate(board, i)) {
            Board* next_board = b_clone(board);
            b_move(next_board, i);

            Node* next_node = s_negamax(next_board);

            if (next_node->best_score * mod > best->best_score * mod)
            {
                best->best_score = next_node->best_score;
                best->best_move  = i; 
            }

            free(next_node);
        }
    }

    return best;
}
