#include "gtest/gtest.h"
#include "InternalLogger.h"
#include "ILogger.h"
#include "LoggerFactory.h"
#include "ConsoleLoggerProvider.h"

namespace Connectivity
{
	TEST(InternalLoggerTests, Constructor) 
	{
		/*auto factory = std::make_shared<LoggerFactory>();
		InternalLogger logger(factory, "test");

		EXPECT_EQ("test", logger.name);

		logger.debug("test");*/
	}
	TEST(InternalLoggerTests, AddProvider)
	{
		/*auto factory = std::make_shared<LoggerFactory>();
		auto provider = std::make_shared<ConsoleLoggerProvider>();


		InternalLogger logger(factory, "test");

		logger.addProvider(provider);
		
		EXPECT_EQ("test", logger.name);

		logger.debug("test");*/

	}
	
}