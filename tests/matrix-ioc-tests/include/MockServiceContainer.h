#pragma once
#include "ioc/IServiceContainer.h"
#include "ioc/IServiceProvider.h"
#include "MockServiceprovider.h"

namespace Matrix
{
	class MockServiceContainer: public IServiceContainer
	{
	public:
		std::shared_ptr<void> getService(const TypeInfo* typeInfo) override;

		IServiceContainer & registerService(ServiceDescriptor* descriptor) override;

	private:
		std::vector<ServiceDescriptor*> mDescriptors;
	};

}