#include "MockServiceContainer.h"

namespace Connectivity
{
	std::shared_ptr<void> MockServiceContainer::getService(const TypeInfo * typeInfo)
	{
		return std::shared_ptr<void>();
	}
	IServiceContainer & MockServiceContainer::registerService(ServiceDescriptor * descriptor)
	{
		return *this;
	}
}