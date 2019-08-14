#pragma once
#include "ioc/ServiceContainer.h"
#include "ioc/IServiceContainer.h"
#include "ioc/IServiceProvider.h"
#include "logging/LoggerFactory.h"

#include <memory>


namespace Matrix
{
	using std::shared_ptr;


	class TestServices
	{
	public:
		TestServices();
		~TestServices();

		static shared_ptr<IServiceProvider> createServiceProvider();
	};

}