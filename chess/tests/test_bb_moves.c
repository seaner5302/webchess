#define MAIN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/bitboard.h"
#include "../headers/bb_moves.h"


int main(void) {
    Bitboard bitboard;
    init_bitboard(&bitboard);
    for (int i=0;i<64;i++) printf(" PIECE COLOR IS: %d   |",get_piece_color(&bitboard, i));
    for (int i=0;i<64;i++) printf(" PIECE TYPE IS: %d   |",get_piece_type(&bitboard, i));

    return 0;
}