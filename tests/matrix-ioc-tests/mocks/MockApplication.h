#pragma once
#include "ApplicationBase.h"

namespace Connectivity
{
	class MockApplication: public ApplicationBase
	{
	public:
		MockApplication();
		~MockApplication();

	protected :
		void registerServices(std::shared_ptr<IServiceContainer> container) override;
	};

}