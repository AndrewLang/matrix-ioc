#pragma once
#include "IServiceProvider.h"

namespace Connectivity
{
	class MockServiceprovider : public IServiceProvider
	{
	public:
		std::shared_ptr<void> getService(const TypeInfo* typeInfo) override;
	};
}
