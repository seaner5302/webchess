all_tests : test*

testString1 : board.o moves.o testString1.o
	gcc board.o moves.o testString1.o -o testString1.x

testPawnMoves1 : board.o moves.o testPawnMoves1.o
	gcc board.o moves.o testPawnMoves1.o -o testPawnMoves1.x

testPawnMoves2 : board.o moves.o testPawnMoves2.o
	gcc  board.o moves.o testPawnMoves2.o -o testPawnMoves2.x

testFEN1 : board.o moves.o testFEN1.o
	gcc  board.o moves.o testFEN1.o -o testFEN1.x

testFEN2 : board.o moves.o testFEN2.o
	gcc  board.o moves.o testFEN2.o -o testFEN2.x

testBitboard : bitboard.o testBitboard.o
	gcc bitboard.o testBitboard.o -o testBitboard.x

testBitboardStr : bitboard.o testBitboardStr.o
	gcc bitboard.o testBitboardStr.o -o testBitboardStr.x

testBitboardFEN : bitboard.o testBitboardFEN.o
	gcc bitboard.o testBitboardFEN.o -o testBitboardFEN.x

testBitboardFEN2 : bitboard.o testBitboardFEN2.o
	gcc bitboard.o testBitboardFEN2.o -o testBitboardFEN2.x

test_bb_moves : bb_moves.o bitboard.o test_bb_moves.o
	gcc bb_moves.o bitboard.o test_bb_moves.o -o test_bb_moves.x

test_bb_moves2 : bb_moves.o bitboard.o test_bb_moves2.o
	gcc bb_moves.o bitboard.o test_bb_moves2.o -o test_bb_moves2.x

test_bb_moves2.o : tests/test_bb_moves2.c
	gcc -c tests/test_bb_moves2.c

test_bb_moves.o : tests/test_bb_moves.c
	gcc -c tests/test_bb_moves.c

bb_moves.o : bb_moves.c
	gcc -c bb_moves.c

testBitboardFEN2.o : tests/testBitboardFEN2.c
	gcc -c tests/testBitboardFEN2.c

testBitboardFEN.o : tests/testBitboardFEN.c
	gcc -c tests/testBitboardFEN.c

testBitboardStr.o : tests/testBitboardStr.c
	gcc -c tests/testBitboardStr.c

testBitboard.o : tests/testBitboard.c
	gcc -c tests/testBitboard.c

testFEN2.o : tests/testFEN2.c
	gcc -c tests/testFEN2.c

testFEN1.o : tests/testFEN1.c
	gcc -c tests/testFEN1.c

testPawnMoves1.o : tests/testPawnMoves1.c
	gcc -c tests/testPawnMoves1.c

testPawnMoves2.o : tests/testPawnMoves2.c
	gcc -c tests/testPawnMoves2.c

testString1.o : tests/testString1.c 
	gcc -c tests/testString1.c

board.o : board.c headers/board.h
	gcc -c board.c

bitboard.o : bitboard.c headers/bitboard.h
	gcc -c bitboard.c

moves.o : moves.c headers/moves.h headers/board.h
	gcc -c moves.c

.PHONY: clean

clean : 
	rm *.o *.x