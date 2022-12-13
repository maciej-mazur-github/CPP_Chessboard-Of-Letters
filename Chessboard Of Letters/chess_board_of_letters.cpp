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
	figureCounter = 0;
}



void ChessBoardOfLetters::listFieldsAndFigures()
{
	if (figureCounter == 0)
	{
		cout << "\n\nThere are no inserted figures/letters on the chess board yet.\n\n\n";
		return;
	}

	cout << "\n\nThe reserved fields and figures/letters are as follows:\n";

	for (int i = 0; i < figureCounter; i++)
	{
		cout << "\t" << i + 1 << ")\t" << *figuresPtr[i] << " at " << fieldsPtr[i][0] << fieldsPtr[i][1] << endl;
	}

	cout << "\n\n\n";
}


int ChessBoardOfLetters::validateCoordinatesChoice(string& coordinateChoice)
{
	char columnNumber = _getche();
	columnNumber = tolower(columnNumber);
	
	if (columnNumber == 120)    // if the 'x' key was pressed
	{
		coordinateChoice = "\t'x' key was pressed. Ending letter insertion process...\n";
		return 2;
	}
	else if (columnNumber >= 105 && columnNumber <= 122)       // if any of letters i-z was pressed (chess board has only got a-h columns)
	{
		coordinateChoice = "Column letter out of range. Please try again";
		return 1;
	}
	else if (columnNumber >= 97 && columnNumber <= 104)      // if a correct letter was entered
	{
		coordinateChoice = columnNumber;
	}
	else                          // if any other other character was entered by the user, e.g. #, $, 8, 2 etc.
	{
		coordinateChoice = "Wrong character was used as a column number. Only a-h letters are allowed (uppercase A-H are also acceptable)\n";
		return 1;
	}



	char rowNumber = _getche();
	rowNumber = tolower(rowNumber);    // in case uppercase X was pressed here

	if (rowNumber == 120)    // if the 'x' key was pressed
	{
		coordinateChoice = "\t'x' key was pressed. Ending letter insertion process...\n";
		return 2;
	}
	else if (rowNumber == '0' || rowNumber == '9')    // 0 and 9 are not available as chess board row numbers
	{
		coordinateChoice = "Invalid chess board row number entered. Numbers 1 - 8 are allowed only.Please try again";
		return 1;
	}
	else if (rowNumber >= 49 && rowNumber <= 56)       // correct number entered
	{
		coordinateChoice += rowNumber;
		return 0;
	}
	else                          // if any other other character was entered by the user, e.g. #, $, a, C etc.
	{
		coordinateChoice = "Wrong character was used as a row number. Only 1-8 digits are allowed\n";
		return 1;
	}

}


int ChessBoardOfLetters::validateLetterChoice(string& letterChoice)
{
	char letter = _getche();
	letter = toupper(letter);

	if (letter == 120)    // if the 'x' key was pressed
	{
		letterChoice = "\t'x' key was pressed. Ending letter insertion process...\n";
		return 2;
	}
	else if ((letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122))      // if a correct letter was entered
	{
		letterChoice = letter;
		return 0;
	}
	else                          // if any other other character was entered by the user, e.g. #, $, 8, 2 etc.
	{
		letterChoice = "\tWrong character was used to be inserted. Only letters (both upper and lower case) are allowed\n";
		return 1;
	}
}


void ChessBoardOfLetters::insertFigures()
{
	cout << "Now you will have a chance to insert up to 64 letters into your chess board. Once a given field is taken you are no longer able to use it again.\n";
	cout << "Each time you will be first asked about the field coordinates (e.g. a3, d7, h1 etc.) at which you need the letter to be inserted, then you will be asked about the letter itself.\n\n";
	cout << "\n\tPressing 'x' will end the insertion process." << endl;

	bool quit = false;
	int figureNumberLimit = CHESS_BOARD_SIZE * CHESS_BOARD_SIZE;
	int coordinatesValidationResult;
	int letterValidationResult;
	string coordinates;
	string letterChoice;
	
	while (!quit && figureCounter < figureNumberLimit)
	{
		cout << "\n\n\n\tChoose coordinates: ";
		coordinatesValidationResult = validateCoordinatesChoice(coordinates);

		switch (coordinatesValidationResult)
		{
		case 1:
			cout << "\n\t" << coordinates << endl;
			coordinates = "";
			continue;
			break;
		case 2:
			cout << "\n\t" << coordinates << endl;
			quit = true;
			continue;
			break;
		}

		cout << "\n\tChoose letter to be inserted: ";
		letterValidationResult = validateLetterChoice(letterChoice);


		switch (letterValidationResult)
		{
		case 1:
			cout << "\n\t" << letterChoice << endl;
			letterChoice = "";
			continue;
			break;
		case 2:
			cout << "\n\t" << letterChoice << endl;
			quit = true;
			continue;
			break;
		}

		if (!insertion(coordinates, letterChoice))
		{
			cout << "\n\tField " << coordinates << " has already been taken. Try with another one...\n";
			continue;
		}
		else
		{
			//cout << "\nLetter " << letterChoice << " successfully inserted into field " << coordinates << endl;
			letterChoice = "";
			coordinates = "";
		}
		
	}

	printChessBoard();
}


bool ChessBoardOfLetters::insertion(string coordinates, string letterChoice)
{
	char columnLetter = coordinates.at(0);
	int actualColumnNumber = (int)columnLetter - 97;
	char rowLetter = coordinates.at(1);
	int actualRowNumber = (int)rowLetter - 49;

	if (chessBoardPtr[actualRowNumber][actualColumnNumber] != '_')    //  if the field is already taken
	{
		return false;
	}
	else
	{
		chessBoardPtr[actualRowNumber][actualColumnNumber] = letterChoice.at(0);
		figuresPtr[figureCounter] = &chessBoardPtr[actualRowNumber][actualColumnNumber];
		fieldsPtr[figureCounter][0] = columnLetter;
		fieldsPtr[figureCounter][1] = rowLetter;
		figureCounter++;
		return true;
	}
}


void ChessBoardOfLetters::printChessBoard()
{
	cout << endl;

	for (int i = CHESS_BOARD_SIZE - 1; i >= 0; i--)
	{
		cout << "\t" << i + 1 << "|\t";

		for (int j = 0; j < CHESS_BOARD_SIZE; j++)
		{
			cout << chessBoardPtr[i][j] << "\t";
		}

		cout << "\n\t |\t" << "\n\t |\t" << endl;
	}

	cout << "\t |";

	for (int i = 0; i < CHESS_BOARD_SIZE * 8; i++)
	{
		cout << "_";
	}

	cout << "\n\t\t";

	for (char c = 'A'; c < 'I'; c++)
	{
		cout << c << "\t";
	}

	cout << endl << endl << endl;

	listFieldsAndFigures();
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