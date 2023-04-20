#include "Header.h"
#include "functions.h"

const char* WRONG_INPUT = "wrong input";

int main()
{
	set_terminate(newTerminate);
	Metropolyn metro;
	int numOfHighWays, numOfOps;
	char input;
	try
	{
		cout << "Please enter number of highways: " << endl;
		cin >> numOfHighWays;
		if (numOfHighWays < 0)
			throw WRONG_INPUT;
		cout << "Please enter number of operations: " << endl;
		cin >> numOfOps;
		if (numOfOps < 0)
			throw WRONG_INPUT;
		for (int i = 0; i < numOfOps; i++)
		{
			printOp();
			cin >> input;
			if ((i == 0 && input != 'a') || (i != 0 && input == 'a')) 
				throw WRONG_INPUT;
			if (input == 'a')
				metro.Init(numOfHighWays);
			else if (input == 'b')
				addBridgeCasing(metro, numOfHighWays);
			else if (input == 'c')
				WhichRoadCasing(metro);
			else if (input == 'd')
				printCasing(metro, numOfHighWays);
			else
				throw WRONG_INPUT;
		}
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	return 0;
}
