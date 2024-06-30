#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/bitboard.h"
#define MAIN

int main ()
{
    char cont[3] = {0};//[0]==char [1] == null terminator [2] == carriage return 
    FILE *fptr;

    while (*cont != 'q' && *cont !='Q')
    {
        char FEN[100] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RBNQKNBR w KQkq 0 0";
        Bitboard board = FEN_to_board(FEN);
        printf ("Press [Q] to end: ");
        fgets(cont, sizeof(cont), stdin);
        fptr = fopen("output.txt", "r");
        fgets(myString, 100, fptr);
        printf("%s", FEN);
        // char * token = strtok(myString, "\"");
        // strtok(NULL, "\"");
        // strtok(NULL, "\"");
        // token = strtok(NULL, "\"");
        printf("%s",bitboard_string(&board, 0));
        clear_board(&board);
    }

    printf ("ENDING\n");


    return 0;
}
