#include <stdio.h>
#include <stdlib.h>
#include "../headers/board.c"

#include <stdio.h> 
#include <cjson/cJSON.h> 

int main(void) {
  Piece pawn;
  Board board;

  // test init_piece by making pawn
  init_piece(&pawn, 0, 'p', 8);
  printf("On square: %d\n", pawn.square);

  return 0;
}