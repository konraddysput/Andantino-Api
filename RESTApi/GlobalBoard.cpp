#include "GlobalBoard.h"
#include "Game.h"
#include <stdexcept>


GlobalBoard::GlobalBoard(int boardWidth, int boardHeight) {
	_boardWidth = boardWidth * 2;
	_boardHeight = boardHeight * 2;

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
GlobalBoard::GlobalBoard(int board[20][20]) {
	_boardWidth = 20;
	_boardHeight = 20;
	_duplicationBoard = new Move *[_boardWidth];
	for (size_t i = 0; i < _boardWidth; i++)
	{
		_duplicationBoard[i] = new Move[_boardHeight];
		for (size_t j = 0; j < _boardHeight; j++)
		{
			switch (board[i][j]) {
			case 0:
				_duplicationBoard[i][j] = None;
				break;
			case 1:
				_duplicationBoard[i][j] = Bot;
				break;
			case 2:
				_duplicationBoard[i][j] = Player;
				break;
			default:
				_duplicationBoard[i][j] = Out;
			}
		}
	}
}

GlobalBoard::GlobalBoard(int** board) {
	_boardWidth = 20;
	_boardHeight = 10;
	_duplicationBoard = new Move *[_boardHeight];
	for (size_t i = 0; i < _boardHeight; i++)
	{
		_duplicationBoard[i] = new Move[_boardWidth];
		for (size_t j = 0; j < _boardWidth; j++)
		{
			switch (board[i][j]) {
			case 0:
				_duplicationBoard[i][j] = None;
				break;
			case 1:
				_duplicationBoard[i][j] = Bot;
				break;
			case 2:
				_duplicationBoard[i][j] = Player;
				break;
			default:
				_duplicationBoard[i][j] = Out;
			}
		}
	}
}


GlobalBoard::GlobalBoard(Move** board) {
	_boardWidth = 20;
	_boardHeight = 20;
	_duplicationBoard = board;
}

Move** GlobalBoard::getDuplicatedBoard() {
	return _duplicationBoard;
}
Move GlobalBoard::getBoardValue(int height, int width) {
	if (height < 0 || width < 0 || width >= getBoardWidth() || height >= getBoardHeight()) {
		return None;
	}
	return _duplicationBoard[height][width];
}

void GlobalBoard::setBoardValue(int height, int width, Move value) {
	if (height < 0 || width < 0) {
		throw std::invalid_argument("Bad argument passed");
	}
	_duplicationBoard[height][width] = value;
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
int GlobalBoard::getBoardHeight() {
	return _boardHeight;
}

int GlobalBoard::getBoardWidth() {
	return _boardWidth;
}

GlobalBoard::~GlobalBoard() {
	for (int i = 0; i < 10; i++) {
		delete[] _duplicationBoard[i];
	}
	delete[] _duplicationBoard;
}