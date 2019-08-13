//#include "stdafx.h"
#include "ioc/ServiceDescriptor.h"

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
