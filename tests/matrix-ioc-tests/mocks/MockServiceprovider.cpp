#include "MockServiceprovider.h"

namespace Connectivity
{

	

	std::shared_ptr<void> MockServiceprovider::getService(const TypeInfo * typeInfo)
	{
		return std::shared_ptr<void>();
	}

}