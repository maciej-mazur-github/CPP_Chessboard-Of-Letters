#pragma once
using namespace std;
#define CHESS_BOARD_SIZE 8

class ChessBoardOfLetters
{
	char** chessBoardPtr;
	char** fieldsPtr;
	char** figuresPtr;
	void chessBoardCreator();
	void figureCreator();
	void fieldCreator();
	void listFieldsAndFigures();
public:
	ChessBoardOfLetters();
	void insertFigures();
	void printChessBoard();
	~ChessBoardOfLetters();
};

