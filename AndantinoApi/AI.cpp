#include "AI.h"



void AI::performMove(GlobalBoard &board) {

}
//
//AI::AI(GlobalBoard &board) {
//	_board = board;
//}

//AIMove AI::checkWin(int player) {
//
//	/*bool CheckWin(int  **board, int height, int width, int player)
//	{*/
//	int howManyMatches = 0;
//	//Sprawdzanie w poziomie - BEGIN
//	for (int i = 0; i < _board.getBoardHeight(); i++)
//	{
//		if (i % 2 == 0)
//			for (int j = 0; j < _board.getBoardWidth(); j += 2)
//			{
//				if (j + 8 <  _board.getBoardWidth())
//				{
//					for (int k = 0; k < 9; k += 2)
//					{
//						if (_board.getBoardValue(i,j+k) == player)
//						{
//							howManyMatches++;
//							if (howManyMatches == 5)
//								return true;
//						}
//						else
//						{
//							howManyMatches = 0;
//							break;
//						}
//					}
//				}
//			}
//		if (i % 2 != 0)
//			for (int j = 1; j < _board.getBoardWidth(); j += 2)
//			{
//				if (j + 8 < _board.getBoardWidth())
//				{
//					for (int k = 0; k < 9; k += 2)
//					{
//						if (_board.getBoardValue(i,j+k) == player)
//						{
//							howManyMatches++;
//							if (howManyMatches == 5)
//								return true;
//						}
//						else
//						{
//							howManyMatches = 0;
//							break;
//						}
//					}
//				}
//			}
//	}
//	//Sprawdzanie w poziomie - END
//	//Sprawdzanei Skos /  -Begin
//	for (int i = 0; i < _board.getBoardHeight(); i++)
//	{
//		if (i % 2 == 0)
//		{
//			howManyMatches = 0;
//			for (int j = 0; j <_board.getBoardWidth(); j += 2)
//			{
//				if (j - 4 >= 0 && i + 4 < _board.getBoardHeight())
//				{
//					for (int k = 0; k < 5; k++)
//					{
//						if (_board.getBoardValue(i+k,j-k) == player)
//						{
//							howManyMatches++;
//							if (howManyMatches == 5)
//								return true;
//						}
//						else
//						{
//							howManyMatches = 0;
//							break;
//						}
//					}
//				}
//			}
//			howManyMatches = 0;
//			for (int j = 0; j < _board.getBoardWidth(); j += 2)
//			{
//				if (j + 4 >= 0 && i + 4 < _board.getBoardHeight())
//				{
//					for (int k = 0; k < 5; k++)
//					{
//						if (_board.getBoardValue(i + k,j + k) == player)
//						{
//							howManyMatches++;
//							if (howManyMatches == 5)
//								return true;
//						}
//						else
//						{
//							howManyMatches = 0;
//							break;
//						}
//					}
//				}
//			}
//		}
//		if (i % 2 != 0)
//		{
//			howManyMatches = 0;
//			for (int j = 1; j < _board.getBoardWidth(); j += 2)
//			{
//				if (j - 4 >= 0 && i + 4 >= 0)
//				{
//					for (int k = 0; k < 5; k++)
//					{
//						if (_board.getBoardValue(i + k,j - k) == player)
//						{
//							howManyMatches++;
//							if (howManyMatches == 5)
//								return true;
//						}
//						else
//						{
//							howManyMatches = 0;
//							break;
//						}
//					}
//				}
//			}
//			howManyMatches = 0;
//			for (int j = 1; j < _board.getBoardWidth(); j += 2)
//			{
//				if (j - 4 >= 0 && i + 4 >= 0)
//				{
//					for (int k = 0; k < 5; k++)
//					{
//						if (_board.getBoardValue(i + k,j - k) == player)
//						{
//							howManyMatches++;
//							if (howManyMatches == 5)
//								return true;
//						}
//						else
//						{
//							howManyMatches = 0;
//							break;
//						}
//					}
//				}
//			}
//		}
//	}
//	//Sprawdzanei Skos /  -END
//	//Sprawdzanie otoczonych -BEGIN
//	int **boardTemp = new int *[_board.getBoardWidth()];
//	for (int i = 0; i < _board.getBoardWidth(); ++i)
//	{
//		boardTemp[i] = new int[_board.getBoardHeight()];
//		for (int j = 0; j < _board.getBoardHeight(); j++)
//		{
//			boardTemp[i][j] = 0;
//		}
//	}
//	/*for (int i = 0; i < _board.getBoardHeight(); i++)
//	{
//		if (i % 2 == 0)
//		{
//			for (int j = 0; j < _board.getBoardWidth(); j += 2)
//			{
//				if (_board.getBoardValue(i,j) == player*(-1))
//					if (globalVar->getBoardValue(i, j) == false)
//						if (checkRing(i, j, board, (player*(-1))) == true)
//							return true;
//			}
//		}
//		if (i % 2 != 0)
//		{
//			for (int j = 1; j < width; j += 2)
//			{
//				if (board[i][j] == player*(-1))
//					if (globalVar->getBoardValue(i, j) == false)
//						if (checkRing(i, j, board, (player*(-1))) == true)
//							return true;
//			}
//		}
//	}*/
//	return false;
//
//}

AIMove AI::getBestMove(GlobalBoard &board) {

	//find all move opportunities
	//we have to make move possible for Andantino AI

	for (size_t boardWidth = 0; boardWidth < board.getBoardWidth(); boardWidth++)
	{
		for (size_t boardHeight = 0; boardHeight < board.getBoardHeight(); boardHeight++)
		{

		}
	}
	return AIMove();
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

//void check_possible_moves(int **board, int height, int width, bool **possible_moves)
bool** AI::checkPossibleMoves()
{
	bool **possibleMovesBoard = createPossibleMoves();
	for (int i = 0; i < _board.getBoardWidth(); i++)
	{
		if (i % 2 == 0)
			for (int j = 0; j < _board.getBoardHeight(); j = j + 2)
			{
				possibleMovesBoard[i][j] = checkSinglePossibleMove(i, j);
			}
		if (i % 2 != 0)
			for (int j = 1; j < _board.getBoardHeight(); j = j + 2)
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
	if (_board.getBoardValue(_board.getBoardHeight(),_board.getBoardWidth()) == None)
	{
		//-1 przeciwnik 
		//1 player
		if (_board.getBoardValue(heightAddres + 1, widthAddres - 1) !=None || _board.getBoardValue(heightAddres + 1, widthAddres - 1) !=Out)
			counter++;
		if (_board.getBoardValue(heightAddres - 1,widthAddres - 1) != None || _board.getBoardValue(heightAddres - 1, widthAddres - 1) != Out)
			counter++;
		if (_board.getBoardValue(heightAddres - 1,widthAddres + 1) != None || _board.getBoardValue(heightAddres - 1, widthAddres + 1) != Out)
			counter++;
		if (_board.getBoardValue(heightAddres + 1, widthAddres + 1) != None || _board.getBoardValue(heightAddres + 1, widthAddres + 1) != Out)
			counter++;
		if (_board.getBoardValue(heightAddres, widthAddres -2) != None || _board.getBoardValue(heightAddres, widthAddres - 2) != Out)
			counter++;
		if (_board.getBoardValue(heightAddres, widthAddres + 2) != None || _board.getBoardValue(heightAddres, widthAddres + 2) != Out)
			counter++;
		if (counter >= 2)
			return true;
	}
	return false;
}