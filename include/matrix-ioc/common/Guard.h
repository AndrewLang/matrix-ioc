#pragma once
#include "ArgumentNullException.h"

namespace Matrix
{
	class Guard
	{
	public:
		template<typename TReturn>
		static void notNull(TReturn arg, const std::string& name);

		static void notEmpty(const std::string& value, const std::string& name);
	};

	template<typename TReturn>
	inline void Guard::notNull(TReturn arg, const std::string& name)
	{
		if (!arg)
			throw ArgumentNullException(name);
	}
}
