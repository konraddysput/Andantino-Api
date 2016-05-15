#pragma once
#include "Game.h"
class GlobalBoard
{
public:
	GlobalBoard(int boardWidth, int boardHeight);
	GlobalBoard(Move** board);
	void clearBoard();
	Move** getDuplicatedBoard();
	void setBoardValue(int width, int height, Move value);
	Move getBoardValue(int width, int height);
	int getBoardWidth();
	int getBoardHeight();

private:
	Move** _duplicationBoard; // aby sprawdzic czy dane pole bylo juz brane pod uwage 
	int _boardHeight;
	int _boardWidth;
};
