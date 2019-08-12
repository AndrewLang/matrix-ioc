#include "gtest/gtest.h"
#include "InstanceCreatorContext.h"
#include "MockServiceContainer.h"
#include "Rectangle.h"
#include "IServiceProvider.h"
#include "IServiceContainer.h"

namespace Connectivity
{
	TEST(InstanceCreatorContextTests, Constructor) {
		auto provider = new MockServiceprovider();

		ParameterFactoryCreator<Rectangle> factoryResolver = [](IServiceProvider* serviceProvider) {
			return ParameterInstanceFactory<Rectangle>("DEFAULT", 20, 30);
		};

		InstanceCreatorContext context(provider, factoryResolver);

		delete provider;
		provider = NULL;
	}

}
