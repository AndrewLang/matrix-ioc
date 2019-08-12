#include "stdafx.h"
#include "Guard.h"
#include "StringExtensions.h"

namespace Matrix
{
	void Guard::notEmpty(const std::string & value, const std::string& name)
	{
		if (StringExtensions::isNullOrEmpty(value))
			throw ArgumentNullException(name);
	}
}