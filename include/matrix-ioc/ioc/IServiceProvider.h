#pragma once
#include "TypeInfo.h"


namespace Matrix
{
	class IServiceProvider
	{
	public:
		virtual std::shared_ptr<void> getService(const TypeInfo* typeInfo) = 0;

		template<class TService>
		std::shared_ptr<TService> resolveService()
		{
			auto service = getService(TypeInfo::From<TService>());
			return std::static_pointer_cast<TService>(service);
		}
	};
}