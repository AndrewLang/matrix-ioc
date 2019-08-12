#pragma once
#include "IServiceContainer.h"
#include "IServiceProvider.h"
#include "MockServiceprovider.h"

namespace Connectivity
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