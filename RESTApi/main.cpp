#include <iostream>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <crow.h>
#include "string"
#include <cstdio>
#include <vector>
#include "GlobalBoard.h"
#include "AI.h"

int* getJsonArray(boost::property_tree::ptree const& pt, bool even) {
	int* localArray = new int[20];
	using boost::property_tree::ptree;
	ptree::const_iterator end = pt.end();
	int currentElement = 0;

	for (ptree::const_iterator it = pt.begin(); it != end; ++it) {
		if (even) {
			localArray[currentElement] = 0;
			currentElement++;
		}
		localArray[currentElement] = atoi(it->second.get_value<std::string>().c_str());
		currentElement++;
		// not available
		if (!even) {
			localArray[currentElement] = 0;
			currentElement++;
		}
	}
	return localArray;
}



int** parseBody(boost::property_tree::ptree const& pt)
{
	using boost::property_tree::ptree;
	ptree::const_iterator end = pt.end();
	int height = 0;
	int ** board = new int*[20];
	for (ptree::const_iterator it = pt.begin(); it != end; ++it) {
		board[height] = getJsonArray(it->second, height % 2);
		height++;
	}
	return board;
}

void printArray(Move** board) {
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 20; j++)
		{
			std::cout << board[i][j];
		}
		std::cout << "\n";
	}
}

int main()
{
	crow::SimpleApp app;
	

	crow::request req;
	req.add_header("Access-Control-Allow-Origin", "*");
	req.url = "/submitResultTest";
	crow::response res;

	app.route_dynamic("/")
		.methods(crow::HTTPMethod::POST)
		([]()
	{
		return "callback({'x': '1','y':'2'})";
	});
	/*app.handle(req, res) {

	}*/

	app.route_dynamic("/submitResult/<string>")
		.methods(crow::HTTPMethod::GET)
		([](std::string content)
	{

		//CROW_LOG_INFO << "msg from client: " << req.body;
		content = content.erase(0, content.find('['));
		std::stringstream ss;
		ss << content;
		boost::property_tree::ptree doc;
		boost::property_tree::read_json(ss, doc);

		GlobalBoard *board = new GlobalBoard(parseBody(doc));
		AI *ai = new AI(*board, 5);

		AIMove move = ai->performMove();
		Move win = None;
		win = ai->CheckWin();
		if (win == None) {
			board->~GlobalBoard();
			free(ai);
			std::string jsonResult = "MainView.PerformMove({'x': '" + std::to_string(move._x) + "','y':'" + std::to_string(move._y) + "',winner:0})";;
			return jsonResult;
		}

		board->~GlobalBoard();
		free(ai);

		std::string jsonResult = "MainView.PerformMove({'x': '0','y':'0',winner:" + std::to_string(win) + "})";
		return jsonResult;
		
	});



	app.port(18080).multithreaded().run();
}
