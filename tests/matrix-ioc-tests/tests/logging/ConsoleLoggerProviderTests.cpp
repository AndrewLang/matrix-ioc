#include "pch.h"
#include "gtest/gtest.h"
#include "ConsoleLoggerProvider.h"
#include "ILogger.h"

namespace Connectivity
{
	TEST(ConsoleLoggerProviderTests, Constructor) {
		ConsoleLoggerProvider provider;
	}
	TEST(ConsoleLoggerProviderTests, CreateLogger)
	{
		ConsoleLoggerProvider provider;
		auto logger = provider.createLogger("test");
				
		ASSERT_EQ("test", logger->name);
	}
}