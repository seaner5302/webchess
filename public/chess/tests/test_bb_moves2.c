#define MAIN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/bitboard.h"
#include "../headers/bb_moves.h"


int main(void) {
    char FEN[100] = "rbnqknbr/pppppppp/P1PPPPP1/8/8/ppppppp1/PPPPPPPP/RNBQKBNR w KQkq 0 0";
    Bitboard bitboard = FEN_to_board(FEN);
    char *bb_str = bitboard_string(&bitboard, 0);
    int sq = 49;
    unsigned int *pawn_moves = get_pawn_moves(&bitboard, sq);
    printf("\nGetting a pawn moves:for pawn on %d %s\n [", --sq, numeric_to_algebraic(++sq));
    for (int i= 0; i <= 3; i++) {
        printf("%d ",pawn_moves[i]+1);
        printf("%s, ",numeric_to_algebraic(pawn_moves[i]));
    }
    printf("]\n\n");

    return 0;
}