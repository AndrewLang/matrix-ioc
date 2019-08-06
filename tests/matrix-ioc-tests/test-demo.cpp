#include "gtest/gtest.h"
#include "Do.h"

using namespace std;
using namespace Matrix;

TEST(TestSamples, VerifyGtest)
{
	EXPECT_EQ(1, 1);
}


TEST(TestSamples, VerifyGtestTrue)
{
	EXPECT_TRUE(true);
}

TEST(DoTests, TestDo)
{
	int tryCount = 0;
	auto lambda = [&](int x) {
		tryCount = x;
	};

	Do<std::function<void(int)>> action(lambda);

	action.attempt(4).sleep(100).start(5);

	cout << "value " << tryCount << endl;
}