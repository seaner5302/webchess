#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/board.h"

int main(void) {
  Board board;
  char *board_stri;

  init_board(&board);
  board_stri = board_string(&board);
  printf("\nStarting Board:\n%s\n\n", board_stri);

  return 0;
}