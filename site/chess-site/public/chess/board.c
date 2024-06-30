// Initialize a board representation
// Generate FEN/string for a board 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifdef MAIN
#else
    #include "headers/board.h"
#endif

// initialize a piece with given fields
void init_piece(Piece *piece, unsigned int color, unsigned int type, unsigned int square)
{
  // if not empty, additional info initialized
  if (type != 0)
  {
    piece->color = color;
    // generate moves later
    switch (type)
    {
    case 1:
      piece->moves = calloc(4, 1);
    case 2:
      piece->moves = calloc(8, 1);
    case 3:
      piece->moves = calloc(13, 1);
    case 4:
      piece->moves = calloc(14, 1);
    case 5:
      piece->moves = calloc(27, 1);
    case 6:
      piece->moves = calloc(8, 1);
    }
  }
  piece->type = type;
  piece->square = square;
  piece->pinned = 0;
}

// initiliaze board with starting position
void init_board(Board *board)
{
  int square_i;
  board->turn = 0;
  board->full_move_count = 0;
  board->half_move_count = 0;
  board->white_king_castle = 1;
  board->white_queen_castle = 1;
  board->black_king_castle = 1;
  board->black_queen_castle = 1;
  board->enpass_target = 0;
  // board->squares fill with respective pieces
  board->squares = calloc(64, sizeof(Piece));

  // white back rank
  init_piece(&(board->squares[0]), 1, 4, 1); // white rook
  init_piece(&(board->squares[1]), 1, 3, 2); // white bishop
  init_piece(&(board->squares[2]), 1, 2, 3); // white knight
  init_piece(&(board->squares[3]), 1, 5, 4); // white queen
  init_piece(&(board->squares[4]), 1, 6, 5); // white king
  init_piece(&(board->squares[5]), 1, 2, 6); // white knight
  init_piece(&(board->squares[6]), 1, 3, 7); // white bishop
  init_piece(&(board->squares[7]), 1, 4, 8); // white rook
  // white pawns
  for (square_i = 8; square_i < 16; square_i++)
  {
    init_piece(&(board->squares[square_i]), 1, 1, square_i + 1);
  }



  // black back rank
  init_piece(&(board->squares[56]), 0, 4, 57); // black rook
  init_piece(&(board->squares[57]), 0, 2, 58); // black knight
  init_piece(&(board->squares[58]), 0, 3, 59); // black bishop
  init_piece(&(board->squares[59]), 0, 5, 60); // black queen
  init_piece(&(board->squares[60]), 0, 6, 61); // black king
  init_piece(&(board->squares[61]), 0, 3, 62); // black bishop
  init_piece(&(board->squares[62]), 0, 2, 63); // black knight
  init_piece(&(board->squares[63]), 0, 4, 64); // black rook
  // black pawns
  for (square_i = 48; square_i < 56; square_i++)
  {
    init_piece(&(board->squares[square_i]), 0, 1, square_i + 1);
  }
}

void init_empty_board(Board *board)
{
  int square_i;
  board->turn = 0;
  board->full_move_count = 0;
  board->half_move_count = 0;
  board->white_king_castle = 1;
  board->white_queen_castle = 1;
  board->black_king_castle = 1;
  board->black_queen_castle = 1;
  board->enpass_target = 0;
  // board->squares fill with respective pieces
  board->squares = calloc(64, sizeof(Piece));
}

char *board_FEN(Board *board)
{
  char *board_str = calloc(85, 1);
  int index;
  int type;
  int color;
  int square_count= 0;
  int empty_count= 0;

  for (index = 0; square_count < 64; index++)
  {
    if (square_count % 8 == 0 && square_count != 0) {
      board_str[index++]= '/';
    }
    type = (board->squares)[square_count].type;
    color = (board->squares)[square_count].color;
    if (type == 0)
    {
      if ((board->squares)[square_count+1].type == 0
      && (square_count+1) % 8 != 0) {
        empty_count++;
        index--;
      }
      else {
        empty_count++;
        board_str[index] = '0' + empty_count;
        empty_count = 0;
      }
    }
    else {
      if (type == 1)
        board_str[index] = color ? 'p' : 'P';
      if (type == 2)
        board_str[index] = color ? 'n' : 'N';
      if (type == 3)
        board_str[index] = color ? 'b' : 'B';
      if (type == 4)
        board_str[index] = color ? 'r' : 'R';
      if (type == 5)
        board_str[index] = color ? 'q' : 'Q';
      if (type == 6)
        board_str[index] = color ? 'k' : 'K';
    }
    square_count++;
  }
  board_str[index]= ' ';
  board_str[++index]= board->turn ? 'b' : 'w';
  board_str[++index]= ' ';

  if (board->white_king_castle) board_str[++index]= 'K';
  if (board->white_queen_castle) board_str[++index]= 'Q';
  if (!board->white_king_castle && !board->white_queen_castle){
    board_str[++index]= '-';
    board_str[++index]= ' ';
  }
  if (board->black_king_castle) board_str[++index]= 'k';
  if (board->black_queen_castle) board_str[++index]= 'q';
  if (!board->black_king_castle && !board->black_queen_castle){
    board_str[++index]= '-';
  }
  board_str[++index]= ' ';

  if (board->enpass_target != 0) {
    board_str[++index]= '`' + ((board->enpass_target+1)/8);
    board_str[++index]= '0' + ((board->enpass_target+1)%8);
    board_str[++index]= ' ';
  }

  if (board->half_move_count == 100){
    board_str[++index]= '1';
    board_str[++index]= '0';
    board_str[++index]= '0';
  }
  else if (board->half_move_count >= 10) {
    board_str[++index]= '0' + board->half_move_count / 10;
    board_str[++index]= '0' + board->half_move_count % 10;
  }
  else board_str[++index]= '0' + board->half_move_count % 10;
  board_str[++index]= ' ';

  if (board->full_move_count >= 10) {
    board_str[++index]= '0' + board->full_move_count / 10;
    board_str[++index]= '0' + board->full_move_count % 10;
  }
  else board_str[++index]= '0' + board->full_move_count % 10;

  return board_str;
}

Board FEN_to_board(char FEN[]) {
  char *rank_str = strtok(FEN, "/");
  Board board;
  int file= 0;
  int rank= 0;
  int blank_total;
  char curr_char;
  int curr_square;
  int file_index;

  init_empty_board(&board);
  int str_index = 0;
  while (rank_str != 0) {
    file = 0;
    blank_total= 0;
    file_index= 0;
    while (file < 8) {
      curr_char = rank_str[file_index];
      curr_square = rank*8 + file;
      // Using ASCII to see if square is number/blank
      if (curr_char <= 57 && curr_char >= 49) {
        blank_total = curr_char - 48;
        // -1 because of file++ at bottom
        file += blank_total;
        file_index++;
      }
      else {
        // 112 -> 'p'
        if (curr_char == 112){
          init_piece(&(board.squares[rank*8+file]), 1, 1, rank*8+file+1);
        }
        // 80 -> 'P'
        else if (curr_char == 80){
          init_piece(&(board.squares[rank*8+file]), 0, 1, rank*8+file+1);
        }
        // 110 -> 'n'
        else if (curr_char == 110){
          init_piece(&(board.squares[rank*8+file]), 1, 2, rank*8+file+1);
        }
        // 78 -> 'N'
        else if (curr_char == 78){
          init_piece(&(board.squares[rank*8+file]), 0, 2, rank*8+file+1);
        }
        // 98 -> 'b'
        else if (curr_char == 98){
          init_piece(&(board.squares[rank*8+file]), 1, 3, rank*8+file+1);
        }
        // 66 -> 'B'
        else if (curr_char == 66){
          init_piece(&(board.squares[rank*8+file]), 0, 3, rank*8+file+1);
        }
        // 114 -> 'r'
        else if (curr_char == 114){
          init_piece(&(board.squares[rank*8+file]), 1, 4, rank*8+file+1);
        }
        // 82 -> 'R'
        else if (curr_char == 82){
          init_piece(&(board.squares[rank*8+file]), 0, 4, rank*8+file+1);
        }
        // 113 -> 'q'
        else if (curr_char == 113){
          init_piece(&(board.squares[rank*8+file]), 1, 5, rank*8+file+1);
        }
        // 81 -> 'Q'
        else if (curr_char == 81){
          init_piece(&(board.squares[rank*8+file]), 0, 5, rank*8+file+1);
        }
        // 107 -> 'k'
        else if (curr_char == 107){
          init_piece(&(board.squares[rank*8+file]), 1, 6, rank*8+file+1);
        }
        // 75 -> 'K'
        else if (curr_char == 75){
          init_piece(&(board.squares[rank*8+file]), 0, 6, rank*8+file+1);
        }
        file_index++;
        file++;
      }
    }
    rank++;
    rank_str = strtok(NULL, "/");
  }
  //printf();
  return board;
}

char *board_string(Board *board) {
  char *board_str = calloc(127, 1);
  int rank;
  int file;
  int type;
  int color;
  int str_index;

  for (rank = 7; rank >= 0; rank--) {
      for (file = 0; file <= 7; file++) {
          type = (board->squares)[rank*8+file].type;
          color = (board->squares)[rank*8+file].color;
          str_index = 63-rank*9+file;
          if (type == 0) {
            board_str[str_index] = '-';
          }
          if (type == 1)
            board_str[str_index] = color ? 'p' : 'P';
          if (type == 2)
            board_str[str_index] = color ? 'n' : 'N';
          if (type == 3)
            board_str[str_index] = color ? 'b' : 'B';
          if (type == 4)
            board_str[str_index] = color ? 'r' : 'R';
          if (type == 5)
            board_str[str_index] = color ? 'q' : 'Q';
          if (type == 6)
            board_str[str_index] = color ? 'k' : 'K';
      }
      board_str[++str_index] = '\n';
    }
  
  
  return board_str;
  
}
