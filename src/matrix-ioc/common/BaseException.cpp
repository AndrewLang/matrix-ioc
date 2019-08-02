#include "../stdafx.h"
#include "BaseException.h"

namespace Matrix
{
	BaseException::BaseException()
	{
	}

	char const * BaseException::what() const
	{
		return buildMessage().c_str();
	}

	string BaseException::buildMessage() const
	{
		return "";
	}	

}