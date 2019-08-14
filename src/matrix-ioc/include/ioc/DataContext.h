#pragma once

#include "IServiceProvider.h"
#include "../common//ObjectMap.h"

#include <memory>
#include <string>


namespace Matrix
{
	class DataContext
	{
	public:
		DataContext();

		DataContext(std::shared_ptr<IServiceProvider> serviceProvider);

		~DataContext();

		std::shared_ptr<IServiceProvider> services();

		template<typename TReturn>
		TReturn getProperty(std::string key, TReturn defaultValue = TReturn())
		{
			if (mDataContainer.contains(key))
			{
				return mDataContainer.getValue<TReturn>(key);
			}
			else
			{
				setProperty(key, defaultValue);
			}

			return defaultValue;
		}

		template<typename TReturn>
		DataContext& setProperty(std::string name, TReturn value)
		{
			mDataContainer.add<TReturn>(name, value);
			return *this;
		}

		DataContext& clear();

	private:
		ObjectMap<std::string> mDataContainer;
		std::shared_ptr<IServiceProvider> mServiceProvider;

	};

}