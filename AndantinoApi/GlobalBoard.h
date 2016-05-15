#pragma once
#include "Game.h"
class GlobalBoard
{
public:
	GlobalBoard(int boardWidth, int boardHeight);
	void clearBoard();
	Move** getDuplicatedBoard();
	void setBoardValue(int width, int height, Move value);
	Move getBoardValue(int width, int height);

private:
	Move** _duplicationBoard;
	int _boardHeight;
	int _boardWidth;
};
