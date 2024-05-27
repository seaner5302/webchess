#define MAIN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/board.h"

int main(void) {
  Board board;
  char *board_str;

  init_board(&board);
  board = FEN_to_board(board_FEN(&board));
  printf("\nStarting Board:\n%s\n\n", board_string(&board));

  return 0;
}