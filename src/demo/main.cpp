
#include "main.h"
#include "Do.h"
#include "ConsoleLogger.h"
#include "StringExtensions.h"
#include "TextFormatter.h"

using namespace std;
using namespace Matrix;

int main()
{
	cout << "IOC/DI Demo App" << endl;

	bool empty = StringExtensions::isNullOrEmpty("test");
	string space = SPACE;
	int padding = StringExtensions::Padding;
	char paddingChar = StringExtensions::PaddingChar;

	int tryCount = 0;
	auto lambda = [&](int x) {
		tryCount = x;
		//string tab = StringExtensions::Tab;
		//string line = StringExtensions::NewLine;
		//cout << line << endl;
	};

	Do<std::function<void(int)>> action(lambda);

	action.attempt(4).sleep(100).start(5);

	cout << "value " << tryCount << endl;


	ConsoleLogger logger("main logger");

	logger.debug("demo application");

	getchar();

	return 0;

}
