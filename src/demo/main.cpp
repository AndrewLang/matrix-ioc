
#include "main.h"
#include "task/Do.h"
#include "logging/ConsoleLogger.h"
#include "common/StringExtensions.h"
#include "common/TextFormatter.h"
#include "common/ArgumentNullException.h"

using namespace std;
using namespace Matrix;

int main()
{
	cout << "IOC/DI Demo App" << endl;

	bool empty = StringExtensions::isNullOrEmpty("test");
	string space = SPACE;
	int padding = StringExtensions::Padding;
	char paddingChar = StringExtensions::PaddingChar;

	ArgumentNullException exception("");

	string tab = Matrix::StringExtensions::Tab;

	int tryCount = 0;
	auto lambda = [&](int x) {
		tryCount = x;		
	};

	Do<std::function<void(int)>> action(lambda);

	action.attempt(4).sleep(100).start(5);

	cout << "value " << tryCount << endl;


	ConsoleLogger logger("main logger");

	logger.debug("demo application")
		.info("log message to info");
	

	auto value = getchar();

	return 0;

}
