#pragma once
#include <string>
#include <map>

#include "ILogger.h"

namespace Matrix
{
	class LogLevelConverter
	{
	public:
		LogLevelConverter();

		~LogLevelConverter();

		std::string toString(LogLevel level);

		/*static LogLevelConverter& Instance()
		{
			static LogLevelConverter instance;
			return instance;
		}*/

	private:	

		std::map<LogLevel, std::string> mValues;
	};

}
