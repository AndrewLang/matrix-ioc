#pragma once
#include "ArgumentNullException.h"

namespace Matrix
{
	class Guard
	{
	public:
		template<typename TReturn>
		static void notNull(TReturn arg, const string& name);

		static void notEmpty(const string& value, const string& name);
	};

	template<typename TReturn>
	inline void Guard::notNull(TReturn arg, const string& name)
	{
		if (!arg)
			throw ArgumentNullException(name);
	}
}
