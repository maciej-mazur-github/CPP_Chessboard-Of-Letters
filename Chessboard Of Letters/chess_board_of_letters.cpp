#include "chess_board_of_letters.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void ChessBoardOfLetters::chessBoardCreator()
{
	chessBoardPtr = new char* [CHESS_BOARD_SIZE];   // dynamically allocate memory for array of pointers char arrays also dynamically allocated below, making it 8x8 board as in chess board

	for (int i = 0; i < CHESS_BOARD_SIZE; i++)
	{
		chessBoardPtr[i] = new char[CHESS_BOARD_SIZE];

		for (int j = 0; j < CHESS_BOARD_SIZE; j++)
		{
			chessBoardPtr[i][j] = '_';
		}
	}
}



void ChessBoardOfLetters::fieldCreator()
{
	fieldsPtr = new char* [CHESS_BOARD_SIZE * CHESS_BOARD_SIZE];    // dynamic allocation of memory for 64-element array of pointers to 2-element arrays (future field coordinates, i.e. a2, b7, d8 etc.)
}