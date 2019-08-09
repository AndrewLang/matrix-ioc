
#include "main.h"
#include "Do.h"
#include "ConsoleLogger.h"

using namespace std;
using namespace Matrix;

int main()
{
	cout << "IOC/DI Demo " << endl;

	int tryCount = 0;
	auto lambda = [&](int x) {
		tryCount = x;
	};

	Do<std::function<void(int)>> action(lambda);

	action.attempt(4).sleep(100).start(5);

	cout << "value " << tryCount << endl;


	ConsoleLogger logger("main");

	logger.debug("demo application");

	getchar();

	return 0;
}
