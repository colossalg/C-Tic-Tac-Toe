#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

typedef enum Result {
    X_WIN = 1, O_WIN = -1, DRAW = 0, NIL = 99
} Result;

typedef struct Board {
    int x_pieces;
    int o_pieces;
    int empty;
    bool x_to_move;
} Board;

extern Board*  b_init(void);
extern Board*  b_clone(Board* board); 
extern void    b_move(Board* board, int move);
extern bool    b_move_validate(Board* board, int move);
extern void    b_print(Board* board);
extern Result  b_result(Board* board);
extern char*   b_result_str(Result res);

#endif /* BOARD_H */
