#define MAIN
#include <stdio.h>
#include <string.h>
#include "../headers/board.h"
#include "../headers/moves.h"

int main(void) {
  Board board;
  Piece pawn;
  unsigned int *pawn_moves;
  int i;
  char str[2];
  str[0] = 'c';
  str[1] = '2';

  init_board(&board);
  pawn = board.squares[8];
  pawn_moves = get_pawn_moves(&pawn, &board);
  printf("\nGetting a pawn moves: for pawn on %s\n[",
        numeric_to_algebraic(pawn.square));
  for (i= 0; i <= 1; i++) {
    printf("%d ",pawn_moves[i]+1);
    printf("%s, ",numeric_to_algebraic(pawn_moves[i]+1));
  }
  printf("]");

  printf("%d ", algebraic_to_numeric("c2"));

  printf("%s ", numeric_to_algebraic(algebraic_to_numeric(str)));
  return 0;
}