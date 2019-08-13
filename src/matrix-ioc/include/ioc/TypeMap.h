#pragma once
#include "../stdafx.h"
#include "TypeInfo.h"

#include <map>

namespace Matrix
{
	template<class TReturn>
	class EXPORT TypeMap
	{
	public:
		void add(const TypeInfo* type, TReturn value);
		TReturn get(const TypeInfo* type);
		bool contains(const TypeInfo* type);
		void clear();
		int size();

	private:
		std::map<const std::string, TReturn> internalMap;
	};


	template<class TReturn>
	inline void TypeMap<TReturn>::add(const TypeInfo* type, TReturn value)
	{
		internalMap.insert(std::make_pair(type->name, value));
	}

	template<class TReturn>
	inline TReturn TypeMap<TReturn>::get(const TypeInfo* type)
	{
		auto iterator = internalMap.find(type->name);
		if (iterator != internalMap.end())
		{
			return iterator->second;
		}
		return NULL;
	}

	template<class TReturn>
	inline bool TypeMap<TReturn>::contains(const TypeInfo* type)
	{
		auto iterator = internalMap.find(type->name);
		return iterator != internalMap.end();

	}

	template<class TReturn>
	inline void TypeMap<TReturn>::clear()
	{
		internalMap.clear();
	}

	template<class TReturn>
	inline int TypeMap<TReturn>::size()
	{
		return static_cast<int>(internalMap.size());
	}

}