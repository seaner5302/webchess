// Generate moves for each individual piece
// Generate all possible moves for a given position

#include <stdlib.h>
#include <stdio.h>
#ifdef MAIN
#else
    #include "headers/moves.h"
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

// unsigned int *get_piece_moves(Piece *piece, Board *board) {
//     if (piece->type == 0 || piece == NULL) {
//         return NULL;
//     }
//     if (piece->type == 1) return get_pawn_moves(piece);
//     if (piece->type == 2) return get_knight_moves(piece);
//     if (piece->type == 3) return get_bishop_moves(piece);
//     if (piece->type == 4) return get_rook_moves(piece);
//     if (piece->type == 5) return get_queen_moves(piece);
//     if (piece->type == 6) return get_king_moves(piece);
// }
// unsigned int *trim_moves(unsigned int *all_moves, unsigned short num_moves, unsigned int *tm){
//     unsigned short index = 0;
//     while (index < num_moves){
//         printf("move: %d", all_moves[index]);
//         if (!(all_moves[index] == 0)){
//             tm[index] = all_moves[index];
//             index++;
//         }
//         else {
//             break;
//         }
//     }
//     return tm;
// }


unsigned int *get_pawn_moves(Piece *piece, Board *board)
{
    unsigned short move_index = 0;
    unsigned int rank;
    unsigned int file;
    unsigned int square = (piece->square-1);

    // Not a pawn, wrong method
    if (board->squares[square].type != 1) {
        return NULL;
    }

    piece->moves = calloc(4, 1);

    if (!(piece->pinned))
    {
        rank = (square) / 8;
        file = (square) % 8;
        // white pawn
        if (piece->color)
        {
            /* if on 2nd rank can move 1 or 2 forward +8
            check if blocked by a white piece
            check diag for black piece
            check square for enpas
            if on 8th rank promotion
            check for pins from bishop rook queen
            */
            // check if piece is above pawn
            if (board->squares[square + 8].type == 0)
            {
                piece->moves[move_index++] = square + 8;
                // move forward twice on first move
                if (rank == 1 && board->squares[square + 16].type == 0)
                {
                    piece->moves[move_index++] = square + 16;
                }
            }
            // check left diagonal capture
            if (file > 0 && ((board->squares[square + 7].type && board->squares[square + 7].color == 0)
                || (square + 7) == board->enpass_target))
            {
                piece->moves[move_index++] = square + 7;
            }
            // check right diagonal capture
            if (file < 7 && ((board->squares[square + 9].type && board->squares[square + 9].color == 0) 
                || (square + 9) == board->enpass_target))
            {
                piece->moves[move_index++] = square + 9;
            }
        }
        else
        {
            if (board->squares[square - 8].type == 0)
            {
                piece->moves[move_index++] = square - 8;
                if (rank == 6 && board->squares[square - 16].type == 0)
                {
                    piece->moves[move_index++] = square - 16;
                }
            }
            // check left diagonal capture
            if (file > 0 && ((board->squares[square - 9].type && board->squares[square - 9].color))
                || (square - 9) == board->enpass_target)
            {
                piece->moves[move_index++] = square - 9;
            }
            // check right diagonal capture
            if (file < 7 && ((board->squares[square - 7].type && board->squares[square - 7].color)
                || (square - 7) == board->enpass_target))
            {
                piece->moves[move_index++] = square - 7;
            }
        }
    }
    return piece->moves;
}
