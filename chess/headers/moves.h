#ifdef MAIN
#else
    #include "board.h"
#endif

char *numeric_to_algebraic(unsigned int numeric);

int algebraic_to_numeric(char *alge);

unsigned int *get_piece_moves(Piece *piece, Board *board);

unsigned int *get_pawn_moves(Piece *piece, Board *board);

unsigned int *get_bishop_moves(Piece *piece, Board *board);

unsigned int *get_knight_moves(Piece *piece, Board *board);

unsigned int *get_rook_moves(Piece *piece, Board *board);

unsigned int *get_queen_moves(Piece *piece, Board *board);

unsigned int *get_king_moves(Piece *piece, Board *board);