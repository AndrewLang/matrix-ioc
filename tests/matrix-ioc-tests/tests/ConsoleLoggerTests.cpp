#include "gtest/gtest.h"
#include "ConsoleLogger.h"
#include "ILogger.h"

namespace Matrix
{
	TEST(ConsoleLoggerTests, Constructor)
	{
		ConsoleLogger logger("test");

	}

	TEST(ConsoleLoggerTests, Log)
	{
		ConsoleLogger logger("test");
		logger.debug("debug message")
			.error("error message");
	}
}