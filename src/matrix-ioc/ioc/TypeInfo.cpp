#include "../stdafx.h"
#include "TypeInfo.h"

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