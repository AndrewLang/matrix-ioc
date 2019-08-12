#pragma once
#include "IComponent.h"

namespace Connectivity
{

	class ApiHandleComponent: public IComponent
	{
	public:
		ApiHandleComponent();

		~ApiHandleComponent();

		void configureServices(std::shared_ptr<IServiceContainer> serviceContainer) override;

		void configure(std::shared_ptr<IServiceProvider> serviceProvider) override;

		void tearDown() override;
	};

}