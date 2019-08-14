#pragma once
#include "ioc/IServiceProvider.h"

namespace Matrix
{
	class MockServiceprovider : public IServiceProvider
	{
	public:
		std::shared_ptr<void> getService(const TypeInfo* typeInfo) override;
	};
}
