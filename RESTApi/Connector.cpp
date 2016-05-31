#include "Connector.h"
#include "GlobalBoard.h"
#include "AI.h"


Connector::Connector(int** board,int depth)
{
	GlobalBoard *globalboard = new GlobalBoard(board);
	AI *ai = new AI(*globalboard, depth);
	
}


Connector::~Connector()
{
}
