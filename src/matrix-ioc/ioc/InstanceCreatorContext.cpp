#include "stdafx.h"
#include "InstanceCreatorContext.h"
#include "IServiceProvider.h"

namespace Matrix
{
	InstanceCreatorContext::InstanceCreatorContext(IServiceProvider* provider, ParameterFactoryCreator<void>  resolver)
		: serviceProvider(provider)
		, factoryResolver(resolver) {}
}