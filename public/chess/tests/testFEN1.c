#define MAIN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/board.h"

int main(void) {
  Board board;
  char *board_str;

  init_board(&board);
  board_str = board_FEN(&board);
  printf("%s", board_str);

  return 0;
}