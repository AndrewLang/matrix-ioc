#include "main.h"
 // #include "Do.h"

#include "gtest/gtest.h"

using namespace std;
// using namespace Matrix;

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	
	return RUN_ALL_TESTS();

	/*cout << "Unit tests for IOC." << endl;

	int tryCount = 0;
	auto lambda = [&](int x) {
		tryCount = x;
	};

	Do<std::function<void(int)>> action(lambda);

	action.attempt(4).sleep(100).start(5);

	cout << "value " << tryCount << endl;

	getchar();

	return 0;*/
}
