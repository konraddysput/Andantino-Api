#include "AI.h"
#include <cstdio>
#include <vector>
#include <limits>


void AI::performMove() {
	AIMove move = getBestMove(_board, Bot,0);
	_board.setBoardValue(move._x, move._y, Bot);
}
bool AI::checkWin(int player) {

	int howManyMatches = 0;
	//Sprawdzanie w poziomie - BEGIN
	for (int i = 0; i < _board.getBoardHeight(); i++)
	{
		if (i % 2 == 0)
			for (int j = 0; j < _board.getBoardWidth(); j += 2)
			{
				if (j + 8 < _board.getBoardWidth())
				{
					for (int k = 0; k < 9; k += 2)
					{
						if (_board.getBoardValue(i, j + k) == player)
						{
							howManyMatches++;
							if (howManyMatches == 5)
								return true;
						}
						else
						{
							howManyMatches = 0;
							break;
						}
					}
				}
			}
		if (i % 2 != 0)
			for (int j = 1; j < _board.getBoardWidth(); j += 2)
			{
				if (j + 8 < _board.getBoardWidth())
				{
					for (int k = 0; k < 9; k += 2)
					{
						if (_board.getBoardValue(i, j + k) == player)
						{
							howManyMatches++;
							if (howManyMatches == 5)
								return true;
						}
						else
						{
							howManyMatches = 0;
							break;
						}
					}
				}
			}
	}
	//Sprawdzanie w poziomie - END
	//Sprawdzanei Skos /  -Begin
	for (int i = 0; i < _board.getBoardHeight(); i++)
	{
		if (i % 2 == 0)
		{
			howManyMatches = 0;
			for (int j = 0; j < _board.getBoardWidth(); j += 2)
			{
				if (j - 4 >= 0 && i + 4 < _board.getBoardHeight())
				{
					for (int k = 0; k < 5; k++)
					{
						if (_board.getBoardValue(i + k, j - k) == player)
						{
							howManyMatches++;
							if (howManyMatches == 5)
								return true;
						}
						else
						{
							howManyMatches = 0;
							break;
						}
					}
				}
			}
			howManyMatches = 0;
			for (int j = 0; j < _board.getBoardWidth(); j += 2)
			{
				if (j + 4 >= 0 && i + 4 < _board.getBoardHeight())
				{
					for (int k = 0; k < 5; k++)
					{
						if (_board.getBoardValue(i + k, j + k) == player)
						{
							howManyMatches++;
							if (howManyMatches == 5)
								return true;
						}
						else
						{
							howManyMatches = 0;
							break;
						}
					}
				}
			}
		}
		if (i % 2 != 0)
		{
			howManyMatches = 0;
			for (int j = 1; j < _board.getBoardWidth(); j += 2)
			{
				if (j - 4 >= 0 && i + 4 >= 0)
				{
					for (int k = 0; k < 5; k++)
					{
						if (_board.getBoardValue(i + k, j - k) == player)
						{
							howManyMatches++;
							if (howManyMatches == 5)
								return true;
						}
						else
						{
							howManyMatches = 0;
							break;
						}
					}
				}
			}
			howManyMatches = 0;
			for (int j = 1; j < _board.getBoardWidth(); j += 2)
			{
				if (j - 4 >= 0 && i + 4 >= 0)
				{
					for (int k = 0; k < 5; k++)
					{
						if (_board.getBoardValue(i + k, j - k) == player)
						{
							howManyMatches++;
							if (howManyMatches == 5)
								return true;
						}
						else
						{
							howManyMatches = 0;
							break;
						}
					}
				}
			}
		}
	}
	//Sprawdzanei Skos /  -END
	//Sprawdzanie otoczonych -BEGIN
	/*int **boardTemp = new int *[_board.getBoardWidth()];
	for (int i = 0; i < _board.getBoardWidth(); ++i)
	{
		boardTemp[i] = new int[_board.getBoardHeight()];
		for (int j = 0; j < _board.getBoardHeight(); j++)
		{
			boardTemp[i][j] = 0;
		}
	}*/
	return false;
}

AIMove AI::chooseBestMove(std::vector<AIMove> moves, Move player) {
	int choosingIndex = 0;
	if (player == Bot) {
		int bestScore = std::numeric_limits<int>::min();
		for (size_t i = 0; i < moves.size(); i++)
		{
			if (moves[i]._moveScore > bestScore) {
				choosingIndex = i;
				bestScore = moves[i]._moveScore;
			}
		}
	}
	else {
		int bestScore = std::numeric_limits<int>::max();
		for (size_t i = 0; i < moves.size(); i++)
		{
			if (moves[i]._moveScore < bestScore) {
				choosingIndex = i;
				bestScore = moves[i]._moveScore;
			}
		}
	}
	return moves[choosingIndex];
}

AIMove AI::getBestMove(GlobalBoard &board, Move player, int depth) {
	//check if someone win so we can return a score
	if (checkWin(Bot)) {
		return  AIMove(10);
	}
	else if (checkWin(Player)) {
		return AIMove(-10);
	}
	else if (!checkWin(None) || depth == _maxDepth) {
		return AIMove(0);
	}
	std::vector<AIMove> moves;

	//find all move opportunities
	//we have to make move possible for Andantino AI
	bool** possibleMoves = checkPossibleMoves();
	for (size_t boardWidth = 0; boardWidth < board.getBoardWidth(); boardWidth++)
	{
		for (size_t boardHeight = 0; boardHeight < board.getBoardHeight(); boardHeight++)
		{
			if (possibleMoves[boardWidth][boardHeight]==1) {
				AIMove move;
				move._x = boardWidth;
				move._y = boardHeight;
				int tempDepth = depth + 1;
				board.setBoardValue(boardWidth, boardHeight, player);
				if (player == Bot) {
					move._moveScore = getBestMove(board, Player, tempDepth)._moveScore;
				}
				else {
					move._moveScore = getBestMove(board, Bot, tempDepth)._moveScore;
				}
				moves.push_back(move);
				board.setBoardValue(boardWidth, boardHeight, None);
			}
		}
	}
	return chooseBestMove(moves, player);
}

int AI::totalMoves() {
	int totalMoves = 0;
	for (size_t i = 0; i < _board.getBoardWidth(); i++)
	{
		for (size_t j = 0; j < _board.getBoardHeight(); j++)
		{
			if (_board.getBoardValue(i, j) != None)
			{
				totalMoves++;
			}
		}
	}
	return totalMoves;
}

bool** AI::createPossibleMoves() {
	bool** possible_moves = new bool*[_board.getBoardWidth()];
	for (size_t i = 0; i < _board.getBoardWidth(); i++)
	{
		possible_moves[i] = new bool[_board.getBoardHeight()];
		for (size_t j = 0; j < _board.getBoardHeight(); j++)
		{
			possible_moves[i][j] = false;
		}
	}
	return possible_moves;
}
//board - plansza


bool** AI::checkPossibleMoves()
{
	bool **possibleMovesBoard = createPossibleMoves();
	for (int i = 0; i < _board.getBoardWidth(); i++)
	{
		for (int j = 0; j < _board.getBoardHeight(); j++)
		{
			possibleMovesBoard[i][j] = checkSinglePossibleMove(i, j);
		}
	}
	return possibleMovesBoard;
}



bool AI::checkSinglePossibleMove(int heightAddres, int widthAddres)
{
	int counter = 0;
	//czy pole jest puste
	if (_board.getBoardValue(heightAddres, widthAddres) == None)
	{
		//-1 przeciwnik 
		//1 player
		if (_board.getBoardValue(heightAddres + 1, widthAddres - 1) != None)
			counter++;
		if (_board.getBoardValue(heightAddres - 1, widthAddres - 1) != None)
			counter++;
		if (_board.getBoardValue(heightAddres - 1, widthAddres + 1) != None)
			counter++;
		if (_board.getBoardValue(heightAddres + 1, widthAddres + 1) != None)
			counter++;
		if (_board.getBoardValue(heightAddres, widthAddres - 2) != None)
			counter++;
		if (_board.getBoardValue(heightAddres, widthAddres + 2) != None)
			counter++;
		if (counter >= 2)
			return true;
	}
	return false;
}