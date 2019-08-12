#pragma once
#include "ServiceContainer.h"
#include "IServiceContainer.h"
#include "IServiceProvider.h"

#include "LoggerFactory.h"

#include <memory>

using std::shared_ptr;

namespace Connectivity
{
	class TestServices
	{
	public:
		TestServices();
		~TestServices();

		static shared_ptr<IServiceProvider> createServiceProvider();
	};

}