#pragma once

#include "ObjectMap.h"

#include <map>
#include <string>
#include <any>

using std::string;
using std::map;
using std::any;

namespace Matrix
{
	class PipelineContext
	{
	public:		
		void abort();

		bool isAborted() const;
		
		template<typename TReturn>
		TReturn getProperty(string key, TReturn defaultValue = TReturn())
		{
			if (mProperties.contains(key))
			{
				return mProperties.getValue<TReturn>(key);
			}
			
			return defaultValue;
		}

		template<typename TReturn>
		PipelineContext& setProperty(string name, TReturn value)
		{
			mProperties.add<TReturn>(name, value);
			return *this;
		}
	private:
		
		ObjectMap<string> mProperties;

		bool mRequestAborted = false;
	};
}