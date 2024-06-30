typedef struct piece
{
  unsigned int color : 1; // 0 black 1 white
  unsigned int type : 3; // 0 empty, 1 pawn, 2 knight, 3 bishop, 4 rook, 5 queen, 6 king
  unsigned int square : 6; // 1-64 for all squares (0 means no move)
  unsigned int pinned : 1; // if pinned by another piece can't move
  unsigned int *moves; // list of all possible moves
} Piece;

typedef struct board
{
  unsigned int turn : 1; // 0 white's turn 1 black's turn
  Piece *squares;
  unsigned int white_king_castle : 1;
  unsigned int white_queen_castle : 1;
  unsigned int black_king_castle : 1;
  unsigned int black_queen_castle : 1;
  unsigned int enpass_target : 5; // 0 means no targets, then square
  unsigned int full_move_count : 9;
  unsigned int half_move_count : 10;
} Board;

void init_piece(Piece *piece, unsigned int color, unsigned int type, unsigned int square);

void init_board(Board *board);

char *board_string(Board *board);

char *board_FEN(Board *board);

Board FEN_to_board(char FEN[]);

char *board_string(Board *board);

void init_empty_board(Board *board);