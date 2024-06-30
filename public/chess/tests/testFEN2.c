#define MAIN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/board.h"

int main(void) {
  char FEN[100] = "rbnqknbr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq 0 0";
  //char FEN[100] = "pppppppp/pppppppp/8/8/8/8/PPPPPPPP/PPPPPPPP w KQkq 0 0";
  Board board = FEN_to_board(FEN);
  printf("%s",board_string(&board));

//   char *tok = strtok(FEN, "/");
//   int i = 0;
//   while (tok != 0) {
//     printf("%s\n", tok);
//     tok = strtok(NULL, "/");   
//   }
  return 0;
}