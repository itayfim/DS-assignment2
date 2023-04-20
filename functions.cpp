#include "Header.h"

const char* ERROR = "wrong input";

void printOp()
{
	cout << "Please enter letter of operation: " << endl;
	cout << "(a) Init\n(b) AddBridge\n(c) WhichRoad\n(d) Print\n";
}


void addBridgeCasing(Metropolyn& metro, int numOfHighways)
{
	float h;
	int r;
	cin >> h >> r;
	if (h <= 0 || r < 1 || r > numOfHighways)
		throw ERROR;
	metro.AddBridge(h, r);
}

void WhichRoadCasing(Metropolyn& metro)
{
	float h;
	cin >> h;
	if(h <= 0)
		throw ERROR;
	metro.WhichRoad(h);
}

void printCasing(Metropolyn& metro, int numOfHighways)
{
	int r;
	cin >> r;
	if (r < 1 || r > numOfHighways)
		throw ERROR;
	metro.print(r);
}

void newTerminate()
{
	cout << "A general error has been occurred, exiting the program." << endl;
	exit(1);
}