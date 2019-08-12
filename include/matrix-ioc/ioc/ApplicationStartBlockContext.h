#pragma once
#include "../pipeline/PipelineContext.h"
#include "../ioc/IServiceProvider.h"


namespace Matrix
{
	class IApplication;
	
	class ApplicationStartBlockContext : public PipelineContext
	{
	public:
		std::shared_ptr<IApplication> application;

		std::shared_ptr<IServiceProvider> serviceProvider;
	};
}