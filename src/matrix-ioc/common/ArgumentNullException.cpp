
#include "ArgumentNullException.h"
#include "TextFormatter.h"

namespace Matrix
{
	ArgumentNullException::ArgumentNullException(const string argument)
		:mArgument(argument)
	{
	}

	string ArgumentNullException::getArgument() const
	{
		return mArgument;
	}

	string ArgumentNullException::buildMessage() const
	{
		TextFormatter formatter;
		return formatter.format("Argument: '", mArgument, "' is NULL.");
	}
}