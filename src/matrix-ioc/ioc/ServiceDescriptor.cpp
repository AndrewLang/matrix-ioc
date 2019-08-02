#include "stdafx.h"
#include "ServiceDescriptor.h"

namespace Matrix
{
	ServiceDescriptor::~ServiceDescriptor()
	{
		
	}


	ServiceDescriptor& ServiceDescriptor::withName(std::string serviceName)
	{
		name = serviceName;
		return *this;
	}
}
