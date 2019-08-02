#include "../stdafx.h"
#include "Guard.h"
#include "StringExtensions.h"

namespace Matrix
{
	void Guard::notEmpty(const string & value, const string& name)
	{
		if (StringExtensions::isNullOrEmpty(value))
			throw ArgumentNullException(name);
	}
}