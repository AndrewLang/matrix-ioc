#pragma once
#include "TypeInfo.h"

using std::shared_ptr;

namespace Matrix
{
	class IServiceProvider
	{
	public:
		virtual shared_ptr<void> getService(const TypeInfo* typeInfo) = 0;

		template<class TService>
		shared_ptr<TService> resolveService()
		{
			auto service = getService(TypeInfo::From<TService>());
			return std::static_pointer_cast<TService>(service);
		}
	};
}