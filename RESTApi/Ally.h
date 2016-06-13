#pragma once
#include <list>
using namespace std;

class Ally
{
public:
	Ally(int width, int height);
	int getWidth();
	int getHeight();
	static list<Ally*> listOfAllies;
	static list<Ally*>::iterator it;
private:
	int _width;
	int _height;

};
