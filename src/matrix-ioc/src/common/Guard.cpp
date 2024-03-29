#include "common/Guard.h"
#include "common/StringExtensions.h"

namespace Matrix
{
	void Guard::notEmpty(const std::string & value, const std::string& name)
	{
		if (StringExtensions::isNullOrEmpty(value))
			throw ArgumentNullException(name);
	}
}