#pragma once

#include "ServiceLifetime.h"
#include "TypeInfo.h"
#include "InstanceCreatorContext.h"

namespace Matrix
{
	class ServiceDescriptor
	{
	public:
		ServiceLifetime lifetime = ServiceLifetime::Singleton;
		
		const TypeInfo* serviceType;
		const TypeInfo* implementationType;

		std::string name;
		std::shared_ptr<void> instance;
		std::shared_ptr<InstanceCreatorContext> creatorContext;

		ObjectFactory instanceCreator;

		template<class TService>
		std::shared_ptr<TService> getInstance()
		{
			if (nullptr != instance && lifetime != ServiceLifetime::Transient)
			{
				return std::static_pointer_cast<TService>(instance);
			}
			else if (instanceCreator)
			{
				instance = instanceCreator();
				return std::static_pointer_cast<TService>(instance);
			}
			else if (creatorContext)
			{
				auto factory = creatorContext->factoryResolver(creatorContext->serviceProvider);
				instance = factory();
				return std::static_pointer_cast<TService>(instance);
			}

			return nullptr;
		};

		~ServiceDescriptor();

		ServiceDescriptor& withName(std::string serviceName);



		template<class TService>
		static ServiceDescriptor* Transient()
		{
			return Describe<TService, TService>(ServiceLifetime::Transient, DefaultInstanceFactory<TService>());
		}
		
		template<class TService, class TImplementation>
		static ServiceDescriptor* Transient()
		{
			return Describe<TService, TImplementation>(ServiceLifetime::Transient, DefaultInstanceFactory<TImplementation>());
		}

		template<class TService, class TImplementation>
		static ServiceDescriptor* Transient(GenericObjectFactory<TService> factory, const std::string name = std::string())
		{
			return Describe<TService, TImplementation>(ServiceLifetime::Transient, factory, nullptr, name);
		}

		template<class TService, class TImplementation>
		static ServiceDescriptor* Transient(std::shared_ptr<InstanceCreatorContext> context, const std::string name = std::string())
		{
			return Describe<TService, TImplementation>(ServiceLifetime::Transient, nullptr, context, name);
		}



		template<class TService>
		static ServiceDescriptor* Singleton()
		{
			return Describe<TService, TService>(ServiceLifetime::Singleton, DefaultInstanceFactory<TService>());
		}

		template<class TService, class TImplementation>
		static ServiceDescriptor* Singleton()
		{
			return Describe<TService, TImplementation>(ServiceLifetime::Singleton, DefaultInstanceFactory<TImplementation>());
		}

		template<class TService, class TImplementation>
		static ServiceDescriptor* Singleton(GenericObjectFactory<TService> factory, const std::string name = std::string())
		{
			return Describe<TService, TImplementation>(ServiceLifetime::Singleton, factory, nullptr, name);
		}

		template<class TService, class TImplementation>
		static ServiceDescriptor* Singleton(std::shared_ptr<InstanceCreatorContext> context, const std::string name = std::string())
		{
			return Describe<TService, TImplementation>(ServiceLifetime::Singleton, nullptr, context, name);
		}



		template<class TService>
		static ServiceDescriptor* Instance(std::shared_ptr<TService> instance)
		{
			auto descriptor = new ServiceDescriptor();
			descriptor->lifetime = ServiceLifetime::Singleton;
			descriptor->serviceType = TypeInfo::From<TService>();
			descriptor->instance = instance;

			return descriptor;
		}



		template<class TService>
		static ServiceDescriptor* Scoped()
		{
			auto descriptor = new ServiceDescriptor();
			descriptor->lifetime = ServiceLifetime::Scoped;
			descriptor->serviceType = &typeid(TService);
			descriptor->implementationType = &typeid(TService);
			descriptor->instanceCreator = DefaultInstanceFactory<TService>();

			return descriptor;
		}

		template<class TService, class TImplementation>
		static ServiceDescriptor* Scoped()
		{
			auto descriptor = new ServiceDescriptor();
			descriptor->lifetime = ServiceLifetime::Scoped;
			descriptor->serviceType = &typeid(TService);
			descriptor->implementationType = &typeid(TService);
			descriptor->instanceCreator = DefaultInstanceFactory<TImplementation>();

			return descriptor;
		}

	private:
		template<class TService, class TImplementation>
		static ServiceDescriptor* Describe(ServiceLifetime lifetime, ObjectFactory instanceCreator, std::shared_ptr<InstanceCreatorContext> context = nullptr, const std::string name = std::string())
		{
			auto descriptor = new ServiceDescriptor();
			descriptor->lifetime = lifetime;
			descriptor->serviceType = TypeInfo::From<TService>();
			descriptor->implementationType = TypeInfo::From<TImplementation>(); //&typeid(TImplementation);
			descriptor->instanceCreator = instanceCreator;
			descriptor->creatorContext = context;
			descriptor->withName(name);

			return descriptor;
		}
	};
}