#include <algorithm>  
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include "Ally.h"
#include "GlobalBoard.h"
#include "AndantinoApi.h"
#include "AI.h"
using namespace std;


int boardWidth = 10;
int boardHeight = 10;
GlobalBoard *globalVar = new GlobalBoard(boardWidth, boardHeight);

void print_board(int **board, int h, int w)
{

	for (int i = 0; i < h; i++)
	{
		cout << endl;
		for (int j = 0; j < w; j++)
		{
			cout << board[i][j];
		}
	}
	printf("\n");
}

bool checkRing(int heightAddres, int widthAddres, int **board, int p)
{
	typedef std::list<Ally*> alliesList;
	alliesList allies;
	bool closed[6];
	bool status = false;

	for (int i = 0; i < 6; i++)
	{
		closed[i] = true;
	}


	globalVar->setBoardValue(heightAddres, widthAddres, Bot);
	if (board[heightAddres][widthAddres] == p)
	{
		if (board[heightAddres + 1][widthAddres - 1] != (p*(-1)))
		{
			if (board[heightAddres + 1][widthAddres - 1] == p)
				allies.push_back(new Ally(heightAddres + 1, widthAddres - 1));
			else
				closed[0] = false;
		}
		if (board[heightAddres - 1][widthAddres - 1] != (p*(-1)))
		{
			if (board[heightAddres - 1][widthAddres - 1] == p)
				allies.push_back(new Ally(heightAddres - 1, widthAddres - 1));
			else
				closed[1] = false;
		}
		if (board[heightAddres - 1][widthAddres + 1] != (p*(-1)))
		{
			if (board[heightAddres - 1][widthAddres + 1] == p)
				allies.push_back(new Ally(heightAddres - 1, widthAddres + 1));
			else
				closed[2] = false;
		}
		if (board[heightAddres + 1][widthAddres + 1] != (p*(-1)))
		{
			if (board[heightAddres + 1][widthAddres + 1] == p)
				allies.push_back(new Ally(heightAddres + 1, widthAddres + 1));
			else
				closed[3] = false;
		}
		if (board[heightAddres][widthAddres - 2] != (p*(-1)))
		{
			if (board[heightAddres][widthAddres - 2] == p)
				allies.push_back(new Ally(heightAddres, widthAddres - 2));
			else
				closed[4] = false;
		}
		if (board[heightAddres][widthAddres + 2] != (p*(-1)))
		{
			if (board[heightAddres][widthAddres + 2] == p)
				allies.push_back(new Ally(heightAddres, widthAddres + 2));
			else
				closed[5] = false;
		}

		for (alliesList::iterator listMyClassIter = allies.begin();
			listMyClassIter != allies.end();
			listMyClassIter++)
		{
			if (globalVar->getBoardValue((*listMyClassIter)->getWidth(), (*listMyClassIter)->getHeight()) ==
				checkRing((*listMyClassIter)->getHeight(), (*listMyClassIter)->getWidth(), board, p) == Player)
			{
				return false;
			}
		}
		for (int i = 0; i < 6; i++)
		{
			if (closed[i] == false)

				return false;
		}
		return true;
	}
}

bool CheckWin(int  **board, int height, int width, int player)
{
	globalVar->clearBoard();
	int howManyMatches = 0;
	//Sprawdzanie w poziomie - BEGIN
	for (int i = 0; i < height; i++)
	{
		if (i % 2 == 0)
			for (int j = 0; j < width; j += 2)
			{
				if (j + 8 < width)
				{
					for (int k = 0; k < 9; k += 2)
					{
						if (board[i][j + k] == player)
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
			for (int j = 1; j < width; j += 2)
			{
				if (j + 8 < width)
				{
					for (int k = 0; k < 9; k += 2)
					{
						if (board[i][j + k] == player)
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
	for (int i = 0; i < height; i++)
	{
		if (i % 2 == 0)
		{
			howManyMatches = 0;
			for (int j = 0; j < width; j += 2)
			{
				if (j - 4 >= 0 && i + 4 < height)
				{
					for (int k = 0; k < 5; k++)
					{
						if (board[i + k][j - k] == player)
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
			for (int j = 0; j < width; j += 2)
			{
				if (j + 4 >= 0 && i + 4 < height)
				{
					for (int k = 0; k < 5; k++)
					{
						if (board[i + k][j + k] == player)
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
			for (int j = 1; j < width; j += 2)
			{
				if (j - 4 >= 0 && i + 4 >= 0)
				{
					for (int k = 0; k < 5; k++)
					{
						if (board[i + k][j - k] == player)
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
			for (int j = 1; j < width; j += 2)
			{
				if (j - 4 >= 0 && i + 4 >= 0)
				{
					for (int k = 0; k < 5; k++)
					{
						if (board[i + k][j - k] == player)
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
	int **boardTemp = new int *[boardWidth];
	for (int i = 0; i < boardWidth; ++i)
	{
		boardTemp[i] = new int[boardHeight];
		for (int j = 0; j < boardHeight; j++)
		{
			boardTemp[i][j] = 0;
		}
	}
	for (int i = 0; i < height; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < width; j += 2)
			{
				if (board[i][j] == player*(-1))
					if (globalVar->getBoardValue(i, j) == false)
						if (checkRing(i, j, board, (player*(-1))) == true)
							return true;
			}
		}
		if (i % 2 != 0)
		{
			for (int j = 1; j < width; j += 2)
			{
				if (board[i][j] == player*(-1))
					if (globalVar->getBoardValue(i, j) == false)
						if (checkRing(i, j, board, (player*(-1))) == true)
							return true;
			}
		}
	}
	return false;
}

int checkWinForTwoPlayers(int **board)
{
	if (CheckWin(board, boardWidth, boardHeight, 1))
	{
		return 1;
	}
	else
	{
		return CheckWin(board, boardWidth, boardHeight, -1) == true ? -1 : 0;
	}
}

//
////postawienie pionka
//void move(int  **board, int height, int width, int h_pos, int w_pos, int player)
//{
//
//	//experimental change, pleas remote below line of code and repair commit
//	int move_counter = 0;
//	switch (move_counter)
//	{
//		case 0:
//		{
//			for (int i = 0; i < height; i++)
//			{
//				if (h_pos == i)
//				{
//					for (int j = 0; j < width; j++)
//					{
//						if (w_pos == j)
//						{
//							board[i][j] = player;
//							move_counter++;
//							break;
//						}
//					}
//					break;
//				}
//			}
//			break;
//		}
//		case 1:
//		{
//			for (int i = 0; i < height; i++)
//			{
//				if (h_pos == i)
//				{
//					for (int j = 0; j < width; j++)
//					{
//						if (w_pos == j)
//						{
//							if (board[i - 2][j - 2] != 0 || board[i][j - 2] != 0 || board[i + 2][j - 2] != 0 || board[i - 2][j] != 0 || board[i + 2][j] != 0 || board[i - 2][j + 2] != 0 || board[i][j + 2] != 0 || board[i + 2][j + 2] != 0)
//							{
//								board[i][j] = player;
//								move_counter++;
//								break;
//							}
//							else
//							{
//								cout << "ruch niedozwolony";
//							}
//						}
//					}
//					break;
//				}
//			}
//			break;
//		}
//		case 2:
//		{
//			for (int i = 0; i < height; i++)
//			{
//				if (h_pos == i)
//				{
//					for (int j = 0; j < width; j++)
//					{
//						if (w_pos == j)
//						{
//<<<<<<< HEAD
//							if (((board[i - 2][j - 2] != 0) && (board[i - 2][j] != 0)) || ((board[i - 2][j] != 0) && (board[i - 2][j + 2] != 0)) || board[i + 2][j - 2] != 0 || ((board[i][j - 2] != 0) && (board[i + 2][j - 2] != 0)) || ((board[i + 2][j - 2] != 0) && (board[i + 2][j] != 0)) || ((board[i + 2][j] != 0) && (board[i + 2][j] != 0)) || ((board[i - 2][j + 2] != 0) && (board[i][j + 2] != 0)) || ((board[i][j + 2] != 0) && (board[i + 2][j] != 0)))
//							{
//								board[i][j] = player;
//								move_counter++;
//								break;
//							}
//							else
//							{
//								cout << "ruch niedozwolony";
//							}
//=======
//							board[i][j] = player;
//							break;
//						}
//						else
//						{
//							cout << "ruch niedozwolony";
//>>>>>>> 5ac7c667756292985bfc01e64a7a9c1a3133ea02
//						}
//					}
//					break;
//				}
//			}
//			break;
//		}
//	}
//}
//
//void check_possible_moves(int **board, int height, int width, bool **possible_moves)
//{
//	switch (move_counter)
//	{
//	case 0:
//	{
//		for (int i = 0; i < height; i++)
//		{
//			for (int j = 0; j < width; j++)
//			{
//				possible_moves[i][j] = true;
//			}
//		}
//		break;
//	}
//	case 1:
//	{
//		for (int i = 0; i < height; i++)
//		{
//			for (int j = 0; j < width; j++)
//			{
//				if (board[i][j] != 0)
//				{
//					possible_moves[i - 2][j - 2] = true;
//					possible_moves[i][j - 2] != true;
//					possible_moves[i + 2][j - 2] != true;
//					possible_moves[i - 2][j + 2] != true;
//					possible_moves[i][j + 2] != true;
//					possible_moves[i + 2][j + 2] != true;
//				}
//			}
//		}
//		break;
//	}
//	case 2:
//	{
//		for (int i = 0; i < height; i++)
//		{
//			for (int j = 0; j < width; j++)
//			{
//				/*if (board[i][j] != 0)
//				{
//				//TODO
//				}*/
//			}
//		}
//		break;
//	}
//	}
//}

int main()
{
	int option = 0;
	int **board = new int *[boardWidth];
	for (int i = 0; i < boardWidth; ++i)
	{
		board[i] = new int[boardHeight];
		for (int j = 0; j < boardHeight; j++)
		{
			board[i][j] = 0;
		}
	}

	GlobalBoard *globalBoard = new GlobalBoard(10, 10);
	globalBoard->setBoardValue(2, 2, Player);
	globalBoard->setBoardValue(2, 3, Player);
	AI *ai = new AI(*globalBoard);

	auto result = ai->checkPossibleMoves();

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout<<result[j][i];
		}
		cout << "\n";
	}

	do
	{
		printf("Podaj opcje \n");
		scanf("%i", &option);
		for (int i = 0; i < boardWidth; i++)
		{
			for (int j = 0; j < boardHeight; j++)
			{
				board[i][j] = 0;
			}
		}
		switch (option)
		{
		case 1:
			cout << "Pe³na tablica" << endl;
			for (int i = 0; i < boardWidth; i++)
			{
				if (i % 2 == 0)
					for (int j = 0; j < boardHeight; j = j + 2)
					{
						board[i][j] = 1;
					}
				if (i % 2 != 0)
					for (int j = 1; j < boardHeight; j = j + 2)
					{
						board[i][j] = 1;
					}
			}

			break;
		case 2:
			cout << "skos poprawny \\" << endl;
			board[5][5] = 1;
			board[6][6] = 1;
			board[2][2] = 1;
			board[3][3] = 1;
			board[4][4] = 1;
			break;
		case 3:
			cout << "skos poprawny /" << endl;
			board[0][4] = 1;
			board[1][3] = 1;
			board[2][2] = 1;
			board[3][1] = 1;
			board[4][0] = 1;
			break;
		case 4:
			cout << "Poziom poprawny" << endl;
			board[2][0] = 1;
			board[2][2] = 1;
			board[2][4] = 1;
			board[2][6] = 1;
			board[2][8] = 1;
			break;
		case 5:
			cout << "Poziom niepoprawny" << endl;
			board[2][0] = 1;
			board[2][2] = 1;
			board[2][4] = 0;
			board[2][6] = 1;
			board[2][8] = 1;
			break;
		case 6:
			cout << "skos niepoprawny\\" << endl;
			board[5][5] = 1;
			board[6][6] = 1;
			board[2][2] = 0;
			board[3][3] = 1;
			board[4][4] = 1;
			break;
		case 7:
			cout << "skos niepoprawny /" << endl;
			board[0][4] = 1;
			board[1][3] = 0;
			board[2][2] = 1;
			board[3][1] = 1;
			board[4][0] = 1;
			break;
		case 8:
			board[3][3] = 1;
			board[3][5] = 1;
			board[4][6] = 1;
			board[5][7] = 1;
			board[6][6] = 1;
			board[6][4] = 1;
			board[5][3] = 1;
			board[4][2] = 1;
			board[5][5] = -1;
			board[4][4] = -1;
			break;
		case 9:
			board[3][3] = -1;
			board[3][5] = -1;
			board[4][6] = -1;
			board[5][7] = -1;
			board[6][6] = -1;
			board[6][4] = -1;
			board[5][3] = -1;
			board[4][2] = -1;
			board[5][5] = 1;
			board[4][4] = 1;
			break;
		default:
			break;
		}


		print_board(board, boardHeight, boardWidth);

		int status = checkWinForTwoPlayers(board);
		if (status == 1)
			cout << "player 1 won" << endl;
		if (status == -1)
			cout << "player 2 won" << endl;
		if (status == 0)
			cout << "noone won" << endl;

	} while (option != 99);
	return 0;
}