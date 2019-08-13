#pragma once
#include "../stdafx.h"
#include <typeinfo>
#include <atomic>
#include <string>

namespace Matrix
{
	class TypeInfo
	{
	public:
		const std::type_info* rawType;
		std::string name;

		TypeInfo(const std::type_info* type)
			: rawType(type)
			, name(getTypeName())
		{}


		template<class TReturn>
		static const TypeInfo* From()
		{
			return new TypeInfo(&typeid(TReturn));
		}

		const TypeInfo* operator=(const std::type_info* type)
		{
			return new TypeInfo(type);
		}

	private:
		static std::atomic<int> InitialCode;

		std::string getTypeName();

	};

}