#pragma once

#include "GlobalBoard.h"


struct AIMove
{
	AIMove() {}
	AIMove(int score) : _moveScore(score) {}
	int _x;
	int _y;
	int _moveScore;
};


class AI
{
public:
	bool** checkPossibleMoves();
	AI(GlobalBoard &board) : _board(board) {}
	void performMove(GlobalBoard &board);

private:
	AIMove getBestMove(GlobalBoard &board);
	
	AIMove checkWin();
	int _AIPlayer;
	int _humanPlayer;
	GlobalBoard _board;
	bool** createPossibleMoves();
	int totalMoves();
	bool checkSinglePossibleMove(int heightAddres, int widthAddres);
};