#include "stdafx.h"
#include "ioc/TypeInfo.h"

namespace Matrix
{
	std::string TypeInfo::getTypeName()
	{
		if (rawType)
		{
			return rawType->name();
		}
		else
		{
			return "UNKNOWN TYPE";
		}
	}
}