#pragma once

#include "GlobalBoard.h"


struct AiMove
{
	int _x;
	int _y;
	int _moveScore;
};


class AI
{
public:
	void performMove(GlobalBoard &board);

private:
	AiMove getBestMove(GlobalBoard &board);
	int _AIPlayer;
	int _humanPlayer;
};