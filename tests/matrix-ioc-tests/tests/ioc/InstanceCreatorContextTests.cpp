#include "gtest/gtest.h"
#include "ioc/InstanceCreatorContext.h"
#include "MockServiceContainer.h"
#include "Rectangle.h"
#include "ioc/IServiceProvider.h"
#include "ioc/IServiceContainer.h"

namespace Matrix
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
