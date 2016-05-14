#include "GlobalBoard.h"
#include "Game.h"
#include <stdexcept>


GlobalBoard::GlobalBoard(int boardWidth, int boardHeight) {
	_boardWidth = boardWidth;
	_boardHeight = boardHeight;

	_duplicationBoard = new Move *[_boardWidth];
	for (int i = 0; i < _boardWidth; ++i)
	{
		_duplicationBoard[i] = new Move[_boardHeight];
		for (int j = 0; j < _boardHeight; j++)
		{
			_duplicationBoard[i][j] = None;
		}
	}
}

Move** GlobalBoard::getDuplicatedBoard() {
	return _duplicationBoard;
}
Move GlobalBoard::getBoardValue(int width, int height) {
	if (height < 0 || width < 0) {
		throw std::invalid_argument("Bad argument passed");
	}
	return _duplicationBoard[width][height];
}

void GlobalBoard::setBoardValue(int width, int height, Move value) {
	if (height < 0 || width < 0) {
		throw std::invalid_argument("Bad argument passed");
	}
	_duplicationBoard[width][height] = value;
}

void GlobalBoard::clearBoard() {
	for (int i = 0; i < _boardWidth; i++)
	{
		for (int j = 0; j < _boardHeight; j++)
		{
			_duplicationBoard[i][j] = None;
		}
	}
}