#include "stdafx.h"
#include "ServiceContainer.h"

namespace Matrix
{
	ServiceContainer::ServiceContainer() {}

	ServiceContainer::ServiceContainer(ServiceContainer && container) { }

	ServiceContainer::~ServiceContainer() { }

	std::shared_ptr<void> ServiceContainer::getService(const TypeInfo* typeInfo)
	{
		return resolveInstance<void>(typeInfo);
	}
	
	IServiceContainer & ServiceContainer::registerService(ServiceDescriptor* descriptor)
	{
		mDescriptors.push_back(descriptor);

		return *this;
	}

	ServiceDescriptor* ServiceContainer::findDescriptor(std::string name)
	{
		ServiceDescriptor* result = nullptr;
		for (auto descriptor : mDescriptors)
		{
			if (descriptor->serviceType->name == name)
			{
				result = descriptor;
				break;
			}
		}

		return result;
	}

	InstanceDescriptor* ServiceContainer::findInstance(const TypeInfo* type)
	{
		return  mInstances.get(type);
	}
}