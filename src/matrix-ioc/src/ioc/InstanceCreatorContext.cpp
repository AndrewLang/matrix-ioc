#include "stdafx.h"
#include "ioc/InstanceCreatorContext.h"
#include "ioc/IServiceProvider.h"

namespace Matrix
{
	InstanceCreatorContext::InstanceCreatorContext(IServiceProvider* provider, ParameterFactoryCreator<void>  resolver)
		: serviceProvider(provider)
		, factoryResolver(resolver) {}
}