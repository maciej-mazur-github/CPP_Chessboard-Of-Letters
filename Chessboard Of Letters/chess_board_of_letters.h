#pragma once
using namespace std;
#define CHESS_BOARD_SIZE 8

class ChessBoardOfLetters
{
	char** chessBoard;
	char** fields;
	char** figures;
	char** chessBoardCreator();
	char** figureCreator();
	char** fieldCreator();
	void listFieldsAndFigures();
public:
	ChessBoardOfLetters();
	void insertFigures();
	void printChessBoard();
	~ChessBoardOfLetters();
};

