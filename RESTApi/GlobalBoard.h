#pragma once
#include "Game.h"
class GlobalBoard
{
public:
	GlobalBoard(int boardWidth, int boardHeight);
	GlobalBoard(Move** board);
	GlobalBoard(int board[20][20]);
	GlobalBoard(int** board);
	void clearBoard();
	Move** getDuplicatedBoard();
	void setBoardValue(int width, int height, Move value);
	Move getBoardValue(int width, int height);
	int getBoardWidth();
	int getBoardHeight();
	~GlobalBoard();

private:
	Move** _duplicationBoard; // aby sprawdzic czy dane pole bylo juz brane pod uwage 
	int _boardHeight;
	int _boardWidth;
};
