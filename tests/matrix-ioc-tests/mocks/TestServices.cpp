#include "TestServices.h"
#include "ILoggerFactory.h"
#include "LoggerFactory.h"
#include "IEnvironmentProfile.h"
#include "TestRuntimeProfile.h"
#include "VsOutputLoggerProvider.h"
#include "platformCheckMacros.h"
#include "IFileLocker.h"
#include "WinFileLocker.h"

namespace Connectivity
{
	TestServices::TestServices()
	{
	}
	
	TestServices::~TestServices()
	{
	}

	shared_ptr<IServiceProvider> TestServices::createServiceProvider()
	{
		auto serviceProvider = std::make_shared<ServiceContainer>();
		serviceProvider->singleton<ILoggerFactory, LoggerFactory>()
			.singleton<IEnvironmentProfile, TestRuntimeProfile>();

#if defined(_WIN32)
		serviceProvider->singleton<IFileLocker, WinFileLocker>();
#endif
		auto loggerFactory = serviceProvider->resolveService<ILoggerFactory>();
		loggerFactory->useProvider<VsOutputLoggerProvider>();


		return serviceProvider;
	}
}