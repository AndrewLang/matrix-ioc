#pragma once

#include "../common/ObjectMap.h"

#include <map>
#include <string>
#include <any>


namespace Matrix
{
	class PipelineContext
	{
	public:		
		void abort();

		bool isAborted() const;
		
		template<typename TReturn>
		TReturn getProperty(std::string key, TReturn defaultValue = TReturn())
		{
			if (mProperties.contains(key))
			{
				return mProperties.getValue<TReturn>(key);
			}
			
			return defaultValue;
		}

		template<typename TReturn>
		PipelineContext& setProperty(std::string name, TReturn value)
		{
			mProperties.add<TReturn>(name, value);
			return *this;
		}
	private:
		
		ObjectMap<std::string> mProperties;

		bool mRequestAborted = false;
	};
}