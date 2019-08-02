#pragma once
#include <string>

using std::string;

namespace Matrix
{
	class LogMessageName
	{
	public:
		LogMessageName(string name) : mName(name) {}

		string getName() {
			return mName;
		}

	private:
		string mName;
	};
}