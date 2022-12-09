#include "chess_board_of_letters.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>



ChessBoardOfLetters::ChessBoardOfLetters()
{
	chessBoardCreator();
	fieldCreator();
	figureCreator();
}


void ChessBoardOfLetters::printChessBoard()
{
	cout << endl;

	for (int i = CHESS_BOARD_SIZE - 1; i >= 0; i--)
	{
		cout << "\t";

		for (int j = 0; j < CHESS_BOARD_SIZE; j++)
		{
			cout << chessBoardPtr[i][j] << "\t";
		}

		cout << endl << endl << endl;
	}
}


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
	int fieldNumber = CHESS_BOARD_SIZE * CHESS_BOARD_SIZE;
	fieldsPtr = new char* [fieldNumber];    // dynamic allocation of memory for 64-element array of pointers to 2-element arrays (future field coordinates, i.e. a2, b7, d8 etc.)

	for (int i = 0; i < fieldNumber; i++)
	{
		fieldsPtr[i] = new char[2];
	}
}


void ChessBoardOfLetters::figureCreator()
{
	int figureNumber = CHESS_BOARD_SIZE * CHESS_BOARD_SIZE;
	figuresPtr = new char* [figureNumber];

	for (int i = 0; i < figureNumber; i++)
	{
		figuresPtr[i] = nullptr;
	}
}