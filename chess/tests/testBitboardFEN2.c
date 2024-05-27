#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/bitboard.h"
#define MAIN

int main(void) {
    Bitboard bitboard;
    char FEN[100] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RBNQKNBR w KQkq 0 0";
    Bitboard board = FEN_to_board(FEN);
    printf("%s",bitboard_string(&board, 1));
    return 0;
}