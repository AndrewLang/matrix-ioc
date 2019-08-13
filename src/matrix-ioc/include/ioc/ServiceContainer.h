#pragma once

#include "IServiceContainer.h"
#include "TypeMap.h"
#include "ServiceLifetime.h"
#include "InstanceDescriptor.h"

namespace Matrix
{
	class ServiceContainer : public IServiceContainer
	{
	public:
		ServiceContainer();

		ServiceContainer(ServiceContainer &&container);

		~ServiceContainer();

		IServiceContainer & registerService(ServiceDescriptor* descriptor) override;

		std::shared_ptr<void> getService(const TypeInfo* typeInfo) override;

	protected:


	private:
		std::vector<ServiceDescriptor*> mDescriptors;

		TypeMap<InstanceDescriptor*> mInstances;

		ServiceDescriptor* findDescriptor(std::string name);

		InstanceDescriptor* findInstance(const TypeInfo* type);
		
		template<class TReturn>
		std::shared_ptr<TReturn> resolveInstance(const TypeInfo* type)
		{
			auto descriptor = findDescriptor(type->name);
			if (descriptor)
			{
				switch (descriptor->lifetime)
				{
				case ServiceLifetime::Scoped:
					return nullptr;
				case ServiceLifetime::Transient:
				{
					auto instance = descriptor->getInstance<TReturn>();
					return std::static_pointer_cast<TReturn>(instance);
				}
				case ServiceLifetime::Singleton:
				default:
				{
					auto instance = findInstance(type);
					if (nullptr != instance)
					{
						return std::static_pointer_cast<TReturn>(instance->instance);
					}
					else
					{
						auto instance = descriptor->getInstance<TReturn>();

						auto instanceDescriptor = new InstanceDescriptor();
						instanceDescriptor->instance = instance;
						mInstances.add(descriptor->serviceType, instanceDescriptor);


						return std::static_pointer_cast<TReturn>(instance);
					}
				}
				}
			}
			else
			{
				throw new std::exception("No type registration found for ");
			}
			return nullptr;
		}
	};
}
