#include <stdlib.h>
#include <stdio.h>
#ifdef MAIN
#else
    #include "headers/bb_moves.h"
#endif

// take in numeric square int 1-64 and convert to
// algebraic notation string length 2 "e4"
char *numeric_to_algebraic(unsigned int numeric) {
    char *algebraic= calloc(2, 1);
    unsigned int rank= (numeric-1) / 8;
    unsigned int file= (numeric-1) % 8;
    algebraic[0]= 'a' + file;
    algebraic[1]= '1' + rank;
    
    return algebraic;
}

// take in algebraic notation string and convert to
// numeric square int 1-64
int algebraic_to_numeric(char *alge) {
    // subtract char is position in ASCII for rank and file
    return (alge[0]-96) + (alge[1]-49) * 8;
}

int get_piece_type(Bitboard *board, int square) {
    if ((board->Wpawn >> square & 1) || (board->Bpawn >> square & 1)) return 1;
    if ((board->Wknight >> square & 1) || (board->Bknight >> square & 1)) return 2;
    if ((board->Wbishop >> square & 1) || (board->Bbishop >> square & 1)) return 3;
    if ((board->Wrook >> square & 1) || (board->Brook >> square & 1)) return 4;
    if ((board->Wqueen >> square & 1) || (board->Bqueen >> square & 1)) return 5;
    if ((board->Wking >> square & 1) || (board->Bking >> square & 1)) return 6;
    return 0;
    
}

int get_piece_color(Bitboard *board, int square) {
    if ((board->Wpawn >> square & 1) || (board->Wknight >> square & 1) ||
    (board->Wbishop >> square & 1) || (board->Wrook >> square & 1) ||
    (board->Wqueen >> square & 1) || (board->Wking >> square & 1)) {
        return 1;
    }

    if ((board->Bpawn >> square & 1) || (board->Bknight >> square & 1) ||
    (board->Bbishop >> square & 1) || (board->Brook >> square & 1) ||
    (board->Bqueen >> square & 1) || (board->Bking >> square & 1)) {
        return 0;
    }
    
    return -1;
}

unsigned int *get_pawn_moves(Bitboard *board, int square) {
    unsigned int *moves = calloc(4, 1);
    int move_index=0;
    if (get_piece_color(board, square) == -1) {
        printf("Square selected does not contain a pawn\n");
        return moves;
    }
    if (get_piece_color(board, square)) {
        if (!(board->Wpawn << (square-8) & 1)) {
                moves[move_index++] = square-8;
        }
        if (square >= 47 && square <= 55) {
            if (!(board->Wpawn << (square-16) & 1)) {
                moves[move_index++] = square-16;
            }
        }
    }
    else {
        if (!(board->Bpawn << (square+8) & 1)) {
                moves[move_index++] = square+8;
        }
        if (square >= 8 && square <= 16) {
            if (!(board->Bpawn << 16 & 1)) {
                moves[move_index++] = square+16;
            }
        }
    }
    return moves;
}
