#include "AI.h"
#include "Ally.h"
#include <cstdio>
#include <vector>
#include <limits>
#include <list>
using namespace std;

Move AI::CheckWin() {
	bool win = checkWin(Bot);
	if (checkWin(Bot))
	{
		return Bot;
	}
	else if (checkWin(Player)) {
		return Player;
	}
	else {
		return None;
	}


}

class globalVariables {
public:
	bool **duplicationBoard;
	globalVariables()
	{
		duplicationBoard = new bool *[20];
		for (int i = 0; i < 20; ++i)
		{
			duplicationBoard[i] = new bool[20];
			for (int j = 0; j < 20; j++)
			{
				duplicationBoard[i][j] = false;
			}
		}
	}

	void clearBoard()
	{
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 20; j++)
				duplicationBoard[i][j] = false;
	}
};
globalVariables globalVar;

AIMove AI::performMove() {
	return getBestMove(_board, Bot, 0);
}

bool AI::checkWin(int player) {

	int howManyMatches = 0;

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
							if (howManyMatches == 4)
								return true;
						}
						else
						{
							howManyMatches = 0;
							break;
						}
					}
				}
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
	return false;
}

bool AI::checkRing(GlobalBoard &board, int player, int heightAddres, int widthAddres)
{

	bool closed[6];
	for (int i = 0; i < 6; i++)
		closed[i] = true;

	bool status = false;
	globalVar.duplicationBoard[heightAddres][widthAddres] = true;

	if (_board.getBoardValue(widthAddres, heightAddres) == player)
	{
		if (_board.getBoardValue(widthAddres + 1, heightAddres - 1) == player || _board.getBoardValue(widthAddres + 1, heightAddres - 1) == None)
		{
			if (_board.getBoardValue(widthAddres + 1, heightAddres - 1) == player)
				Ally::listOfAllies.push_back(new Ally(widthAddres + 1, heightAddres - 1));
			else
				closed[0] = false;
		}
		if (_board.getBoardValue(widthAddres - 1, heightAddres - 1) == player || _board.getBoardValue(widthAddres - 1, heightAddres - 1) == None)
		{
			if (_board.getBoardValue(widthAddres - 1, heightAddres + 1) == player)
				Ally::listOfAllies.push_back(new Ally(widthAddres - 1, heightAddres - 1));
			else
				closed[1] = false;
		}
		if (_board.getBoardValue(widthAddres - 1, heightAddres + 1) == player || _board.getBoardValue(widthAddres - 1, heightAddres + 1) == None)
		{
			if (_board.getBoardValue(widthAddres - 1, heightAddres + 1) == player)
				Ally::listOfAllies.push_back(new Ally(widthAddres - 1, heightAddres + 1));
			else
				closed[2] = false;
		}
		if (_board.getBoardValue(widthAddres + 1, heightAddres + 1) == player || _board.getBoardValue(widthAddres + 1, heightAddres + 1) == None)
		{
			if (_board.getBoardValue(widthAddres + 1, heightAddres + 1) == player)
				Ally::listOfAllies.push_back(new Ally(widthAddres + 1, heightAddres - 1));
			else
				closed[3] = false;
		}
		if (_board.getBoardValue(widthAddres, heightAddres - 2) == player || _board.getBoardValue(widthAddres, heightAddres - 2) == None)
		{
			if (_board.getBoardValue(widthAddres, heightAddres - 2) == player)
				Ally::listOfAllies.push_back(new Ally(widthAddres, heightAddres - 2));
			else
				closed[4] = false;
		}
		if (_board.getBoardValue(widthAddres, heightAddres + 2) == player || _board.getBoardValue(widthAddres, heightAddres + 2) == None)
		{
			if (_board.getBoardValue(widthAddres, heightAddres + 2) == player)
				Ally::listOfAllies.push_back(new Ally(widthAddres, heightAddres + 2));
			else
				closed[5] = false;
		}
	}


	for (Ally::it = Ally::listOfAllies.begin();
		Ally::it != Ally::listOfAllies.end();
		Ally::it++)
	{
		if (globalVar.duplicationBoard[(*Ally::it)->getHeight][(*Ally::it)->getWidth] == false)
			if (checkRing(_board, player, (*Ally::it)->getHeight, (*Ally::it)->getWidth) == false)
				return false;

	}
	for (int i = 0; i < 6; i++)
	{
		if (closed[i] == false)

			return false;
	}
	return true;
}

AIMove AI::chooseBestMove(std::vector<AIMove> &moves, Move& player) {
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
	//bool **possibleMoves = checkPossibleMoves();
	int height = board.getBoardHeight();
	for (size_t boardHeight = 0; boardHeight < board.getBoardHeight(); boardHeight++)
	{
		for (size_t boardWidth = 0; boardWidth < board.getBoardWidth(); boardWidth++)
		{
			if (checkSinglePossibleMove(boardHeight, boardWidth)) {
				AIMove move;
				move._x = boardWidth;
				move._y = boardHeight;
				int tempDepth = depth + 1;
				board.setBoardValue(boardHeight, boardWidth, player);
				if (player == Bot) {
					move._moveScore = getBestMove(board, Player, tempDepth)._moveScore;
				}
				else {
					move._moveScore = getBestMove(board, Bot, tempDepth)._moveScore;
				}
				moves.push_back(move);
				board.setBoardValue(boardHeight, boardWidth, None);
			}
		}
	}
	//for (int i = 0; i < _board.getBoardHeight(); i++) {
	//	delete[] possibleMoves[i];
	//}
	//delete[] possibleMoves;

	return chooseBestMove(moves, player);
}

int AI::totalMoves() {
	int totalMoves = 0;
	for (size_t j = 0; j < _board.getBoardHeight(); j++)
	{
		for (size_t i = 0; i < _board.getBoardWidth(); i++)
		{
			if (_board.getBoardValue(j, i) != None)
			{
				totalMoves++;
			}
		}
	}
	return totalMoves;
}

bool** AI::createPossibleMoves() {
	bool** possible_moves = new bool*[_board.getBoardHeight()];
	for (size_t height = 0; height < _board.getBoardHeight(); height++)
	{
		possible_moves[height] = new bool[_board.getBoardWidth()];
		for (size_t width = 0; width < _board.getBoardWidth(); width++)
		{
			possible_moves[height][width] = false;
		}
	}
	return possible_moves;
}
//board - plansza


bool** AI::checkPossibleMoves()
{
	bool **possibleMovesBoard = createPossibleMoves();
	for (int j = 0; j < _board.getBoardHeight(); j++)
	{
		for (int i = 0; i < _board.getBoardWidth(); i++)
		{
			possibleMovesBoard[j][i] = checkSinglePossibleMove(j, i);
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

AI::~AI() {}