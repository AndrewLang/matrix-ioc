#pragma once
#include "../pipeline/PipelineContext.h"
#include "../ioc/IServiceProvider.h"

using std::shared_ptr;

namespace Matrix
{
	class IApplication;
	
	class ApplicationStartBlockContext : public PipelineContext
	{
	public:
		shared_ptr<IApplication> application;

		shared_ptr<IServiceProvider> serviceProvider;
	};
}