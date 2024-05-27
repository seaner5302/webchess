typedef struct bitboard
{
    unsigned long long Wpawn;
    unsigned long long Wknight;
    unsigned long long Wbishop;
    unsigned long long Wrook;
    unsigned long long Wqueen;
    unsigned long long Wking;

    unsigned long long Bpawn;
    unsigned long long Bknight;
    unsigned long long Bbishop;
    unsigned long long Brook;
    unsigned long long Bqueen;
    unsigned long long Bking;

    short Wcastlelong;
    short Wcastleshort;
    short Bcastlelong;
    short Bcastleshort;
} Bitboard;

void init_bitboard(Bitboard *bitboard);

char *bitboard_string(Bitboard *bitboard, int new_lines);

char *bitboard_FEN(Bitboard *bitboard);

Bitboard FEN_to_board(char FEN[]);

unsigned long long get_occupied_squares(Bitboard *bitboard);
unsigned long long get_empty_squares(Bitboard *bitboard);
unsigned long long get_white_squares(Bitboard *bitboard);
unsigned long long get_black_squares(Bitboard *bitboard);
