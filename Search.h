#ifndef SEARCH_H
#define SEARCH_H

#include "Board.h"

typedef struct Node {
    int best_move;
    int best_score;
} Node;

extern Node* s_minimax(Board* board);
extern Node* s_negamax(Board* board);

#endif /* SEARCH_H */
