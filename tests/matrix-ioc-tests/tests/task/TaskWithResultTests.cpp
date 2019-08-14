#include "gtest/gtest.h"
#include "task/TaskWithResult.h"
#include "logging/VsOutput.h"

namespace Matrix
{
	template<class TReturn, class Function, class... TArgs>
	TReturn TestFunc(Function func, TArgs&&... args) {
		return func(args...);
	};

	template<class TReturn, class TFunction>
	class T {
	public:

		T(TFunction func);

		TReturn wait();

		template<class... TArgs>
		void start(TArgs&&... args);
	private:
		TFunction mFunction;
		std::future<TReturn> mFuture;
	};

	template<class TReturn, class TFunction>
	inline T<TReturn, TFunction>::T(TFunction func)
	{
		mFunction = func;
	}

	template<class TReturn, class TFunction>
	inline TReturn T<TReturn, TFunction>::wait()
	{
		return mFuture.get();
	}

	template<class TReturn, class TFunction>
	template<class ...TArgs>
	inline void T<TReturn, TFunction>::start(TArgs&&... args)
	{
		mFuture = async(std::launch::deferred, mFunction, args...);
	}

	Func<int, int, int> createFunc() 
	{
		return [](int x, int y) {
			VsOutput::writeWithName("Task", "calculate X + y", x, y);
			return x + y;
		};
	}

	Func<bool, int> createIsPrime()
	{
		return [](int value) {
			VsOutput::writeWithName("Task", "Start checking", value, "...");
			for (int i = 2; i < value; ++i) {
				if (value%i == 0)
					return false;
			}
			return true;
		};
	}
	TEST(TaskWithResultTests, FunctionTest) {

		Func<int, int, int> func = createFunc();

		int actual = func(2, 3);

		ASSERT_EQ(5, actual);

		Func<int> func1 = []() {
			return 0;
		};
	}

	TEST(TaskWithResultTests, AsyncTest) {

		Func<int, int, int> func = createFunc();

		auto task = async(std::launch::deferred, func, 2, 3);
		ASSERT_EQ(5, task.get());


		auto task1 = async(std::launch::async, func, 2, 3);
		ASSERT_EQ(5, task1.get());

		auto lambda = [](int a, int b, int c) {
			return a + b + c;
		};

		auto result = TestFunc<int>(lambda, 1, 1, 1);
		ASSERT_EQ(3, result);
	}

	TEST(TaskWithResultTests, TestCode) {
		Func<int, int, int> func = createFunc();

		T<int, Func<int, int, int>> t(func);

		t.start(2, 2);
		int result = t.wait();

		ASSERT_EQ(4, result);
	}

	TEST(TaskWithResultTests, Constructor) {
		Func<int, int, int> func = createFunc();

		TaskWithResult<int, Func<int, int, int>> task(func);

		task.start(2, 3);

		VsOutput::writeWithName("Task", "calculate X + y started");

		int actual = task.wait();
		ASSERT_EQ(5, actual);

		actual = task.start(4, 5).wait();
		ASSERT_EQ(9, actual);
	}

	TEST(TaskWithResultTests, TaskName) {
		Func<int, int, int> func = createFunc();

		TaskWithResult<int, Func<int, int, int>> task(func);

		task.withName("demo");

		ASSERT_EQ("demo", task.name);
	}

	TEST(TaskWithResultTests, IsPrmie) {
		Func<bool, int> func = createIsPrime();

		TaskWithResult<bool, Func<bool, int>> task(func);
		task.withName("prime").start(313222313);
		VsOutput::writeWithName("Task", "start calculate prime");
		bool isPrime = task.wait();

		ASSERT_EQ("prime", task.name);
		ASSERT_TRUE(isPrime);

		isPrime = task.start(313222314).wait();
		ASSERT_FALSE(isPrime);
	}
}