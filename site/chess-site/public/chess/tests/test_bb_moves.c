#define MAIN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/bitboard.h"
#include "../headers/bb_moves.h"


int main(void) {
    char FEN[100] = "rbnqknbr/pppppppp/PPPPPPPP/8/8/pppppppp/PPPPPPPP/RNBQKBNR w KQkq 0 0";
    Bitboard bitboard = FEN_to_board(FEN);
    for (int i=0;i<64;i++){
         printf("%d : %d : %d\n",i,i/8, get_piece_color(&bitboard, i));
    }
    // for (int i=0;i<64;i++) printf(" PIECE TYPE IS: %d   |",get_piece_type(&bitboard, i));

    return 0;
}