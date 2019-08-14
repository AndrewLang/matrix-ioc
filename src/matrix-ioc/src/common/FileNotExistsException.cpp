#include "common/FileNotExistsException.h"
#include "common/TextFormatter.h"

namespace Matrix
{
	FileNotExistsException::FileNotExistsException(const std::string& file)
		: mFile(file)
	{
	}

	std::string FileNotExistsException::buildMessage() const
	{
		TextFormatter formatter;
		return formatter.format("File: '", mFile, "' is NOT found.");
	}	
}