#define MAIN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/bitboard.h"
#include "../headers/bb_moves.h"


int main(void) {
    Bitboard bitboard;
    unsigned int *pawn_moves;
    init_bitboard(&bitboard);
    pawn_moves = get_pawn_moves(&bitboard, 50);
    for (int i= 0; i <= 1; i++) {
        printf("%d ",pawn_moves[i]+1);
        printf("%s, ",numeric_to_algebraic(64 - pawn_moves[i]+1));
    }
    return 0;
}