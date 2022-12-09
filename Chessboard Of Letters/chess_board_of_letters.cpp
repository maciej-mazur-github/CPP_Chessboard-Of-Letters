#include "chess_board_of_letters.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void ChessBoardOfLetters::chessBoardCreator()
{
	chessBoardPtr = new char* [CHESS_BOARD_SIZE];

	for (int i = 0; i < CHESS_BOARD_SIZE; i++)
	{
		chessBoardPtr[i] = new char[CHESS_BOARD_SIZE];

		for (int j = 0; j < CHESS_BOARD_SIZE; j++)
		{
			chessBoardPtr[i][j] = '_';
		}
	}
}