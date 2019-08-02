#pragma once
#include <chrono>
#include <string>
#include <sstream>


using std::chrono::time_point;
using std::chrono::nanoseconds;
using std::chrono::high_resolution_clock;
using std::string;

namespace Matrix
{
	class Stopwatch
	{
	public:
		Stopwatch();

		~Stopwatch();

		Stopwatch& start();

		Stopwatch& stop();

		Stopwatch& reset();

		long long elapsed();

		long long elapsedMilliseconds();

		bool isRunning();

		string format();

	private:
		time_point<high_resolution_clock> mStart;
		nanoseconds mDuration = nanoseconds::zero();
		bool mIsRunning = false;
	};

}