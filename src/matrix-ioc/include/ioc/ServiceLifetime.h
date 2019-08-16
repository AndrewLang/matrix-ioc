#pragma once
#include <vector>
#include <typeinfo>
#include <functional>
#include <memory>

namespace Matrix
{
	class IServiceProvider;

	enum class ServiceLifetime
	{
		Singleton,
		Scoped,
		Transient
	};



	template<typename TReturn, typename  ... TArgs>
	std::unique_ptr<TReturn> uniqueInstanceFactory(TArgs&&... args)
	{
		return std::make_unique<TReturn>(args...);
	};

	template<typename TReturn, typename  ... TArgs>
	std::shared_ptr<TReturn> sharedInstanceFactory(TArgs&&... args)
	{
		return std::make_shared<TReturn>(args...);
	};


	using ObjectFactory = std::function<std::shared_ptr<void>()>;

	using ObjectFactoryCreator = std::function<ObjectFactory()>;
	   
	template<class TService>
	ObjectFactory DefaultInstanceFactory() {
		return [=]() {		
			return std::make_shared<TService>();
		};
	};


	template<typename TReturn>
	using GenericObjectFactory = std::function<std::shared_ptr<TReturn>()>;

	template<typename TReturn, typename  ... TArgs>
	GenericObjectFactory<TReturn> ParameterInstanceFactory(TArgs&&... args)
	{
		return [=]() {
			return std::make_shared<TReturn>(args...);
		};
	};

	template<typename TReturn, typename ... TArgs>
	using ParameterFactoryCreator = std::function<GenericObjectFactory<TReturn>(IServiceProvider* serviceProvider) >;
	
}