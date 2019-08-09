
#include "ConsoleLoggerProvider.h"
#include "ConsoleLogger.h"

namespace Matrix
{
	ConsoleLoggerProvider::ConsoleLoggerProvider()
	{
	}
	
	ConsoleLoggerProvider::~ConsoleLoggerProvider()
	{
	}

	std::shared_ptr<ILogger> ConsoleLoggerProvider::createLogger(std::string name)
	{
		return std::make_shared<ConsoleLogger>(name);
	}

}