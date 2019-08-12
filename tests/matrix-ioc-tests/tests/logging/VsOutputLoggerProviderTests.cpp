#include "pch.h"
#include "gtest/gtest.h"
#include "VsOutputLoggerProvider.h"
#include "ILogger.h"

namespace Connectivity
{
	TEST(VsOutputLoggerProviderTests, Constructor) 
	{
		VsOutputLoggerProvider provider;
	}

	TEST(VsOutputLoggerProviderTests, CreateLogger) {
		VsOutputLoggerProvider provider;

		auto logger = provider.createLogger("test");

		EXPECT_EQ("test", logger->name);
	}
}