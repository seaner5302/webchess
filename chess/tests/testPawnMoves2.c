#define MAIN
#include <stdio.h>
#include <string.h>
#include "../headers/board.h"
#include "../headers/moves.h"

int main(void)
{
    Board board;
    Piece pawn;
    unsigned int *pawn_moves;
    char FEN[100] = "rbnqknbr/pppppppp/p7/8/8/8/PPPPPPPP/RNBQKBNR w KQkq 0 0";
    int i;
    char str[2];
    str[0] = 'c';
    str[1] = '2';

    board = FEN_to_board(FEN);
    printf("%s\n",board_string(&board));
    pawn = board.squares[15];
    pawn_moves = get_pawn_moves(&pawn, &board);
    printf("\nGetting a pawn moves:\nfor pawn on %s\n[", numeric_to_algebraic(16));
    unsigned int curr_move = pawn_moves[0];
    while(curr_move != 0){
        printf("%s", numeric_to_algebraic(curr_move+1));
        curr_move = pawn_moves[++i];
        if (curr_move != 0) {
            printf(", ");
        }
        else {
            printf("]\n");
        }
    }
    return 0;
}