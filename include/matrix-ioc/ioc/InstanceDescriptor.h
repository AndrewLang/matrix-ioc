#pragma once
#include <memory>

namespace Matrix
{
	class InstanceDescriptor
	{
	public:
		std::shared_ptr<void> instance;
	};
}
