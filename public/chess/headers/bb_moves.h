#ifdef MAIN
#else
    #include "bitboard.h"
#endif

char *numeric_to_algebraic(unsigned int numeric);

int algebraic_to_numeric(char *alge);

int get_piece_type(Bitboard *board, int square);

int get_piece_color(Bitboard *board, int square);

unsigned int *get_pawn_moves(Bitboard *board, int square);
