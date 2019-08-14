#include "ApiHandleComponent.h"
#include "ApiHandler.h"


namespace Matrix
{

	ApiHandleComponent::ApiHandleComponent()
	{
	}


	ApiHandleComponent::~ApiHandleComponent()
	{
	}

	void ApiHandleComponent::configureServices(std::shared_ptr<IServiceContainer> serviceContainer)
	{
		serviceContainer->singleton<IApiHandler, ApiHandler>();
	}

	void ApiHandleComponent::configure(std::shared_ptr<IServiceProvider> serviceProvider)
	{
	}

	void ApiHandleComponent::tearDown()
	{
	}

}
