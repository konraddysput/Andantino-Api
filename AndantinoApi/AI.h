#pragma once

#include "GlobalBoard.h"
#include <cstdio>
#include <vector>

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
	AI(GlobalBoard &board,int maxDepth) : _board(board),_maxDepth(maxDepth) {}
	void performMove();
	GlobalBoard _board;
	bool** checkPossibleMoves();
private:
	int _maxDepth;
	AIMove getBestMove(GlobalBoard &board, Move player,int depth);
	AIMove chooseBestMove(std::vector<AIMove> moves, Move player);
	bool checkWin(int player);
	int _AIPlayer;
	int _humanPlayer;
	bool** createPossibleMoves();
	int totalMoves();
	bool checkSinglePossibleMove(int heightAddres, int widthAddres);
};