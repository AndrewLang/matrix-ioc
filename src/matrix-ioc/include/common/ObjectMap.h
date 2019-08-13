#pragma once
#include "MapValueDescriptor.h"

#include <memory>
#include <map>
#include <string>
#include <any>

namespace Matrix
{
	template<class TReturn>
	class ObjectMap
	{
	public:
		template<typename TValue>
		ObjectMap& add(TReturn key, TValue value)
		{
			auto descriptor = std::make_shared<MapValueDescritor>();
			descriptor->value = std::make_shared<TValue>(value);
			
			internalMap[key] = descriptor;

			return *this;
		}
		
		template<typename TValue>
		TValue getValue(TReturn key, TValue defaultValue = TValue())
		{
			auto iterator = internalMap.find(key);
			if (iterator != internalMap.end())
			{
				auto descriptor = iterator->second;
				auto pointer = std::static_pointer_cast<TValue>(descriptor->value);

				return *pointer;
			}
			return defaultValue;
		}
		bool contains(TReturn key);

		void clear();

		int size();
	private:
		std::map<TReturn, std::shared_ptr<MapValueDescritor>> internalMap;
	};


	template<class TReturn>
	inline bool ObjectMap<TReturn>::contains(TReturn key)
	{
		auto iterator = internalMap.find(key);
		return iterator != internalMap.end();
	}

	template<class TReturn>
	inline void ObjectMap<TReturn>::clear()
	{
		internalMap.clear();
	}

	template<class TReturn>
	inline int ObjectMap<TReturn>::size()
	{
		return static_cast<int>(internalMap.size());
	}
}