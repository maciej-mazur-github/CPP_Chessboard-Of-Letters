#pragma once
#include <string>
using namespace std;
#define CHESS_BOARD_SIZE 8

class ChessBoardOfLetters
{
	int figureCounter;
	char** chessBoardPtr;
	char** fieldsPtr;
	char** figuresPtr;
	void chessBoardCreator();
	void figureCreator();
	void fieldCreator();
	void listFieldsAndFigures();
	int validateCoordinatesChoice(string& coordinateChoice);
	int validateLetterChoice(string& letterChoice);
	bool insertion(string coordinates, string letterChoice);
public:
	ChessBoardOfLetters();
	void insertFigures();
	void printChessBoard();
	~ChessBoardOfLetters();
};

