
#include "FileNotExistsException.h"
#include "TextFormatter.h"

namespace Matrix
{
	FileNotExistsException::FileNotExistsException(const string& file)
		: mFile(file)
	{
	}

	string FileNotExistsException::buildMessage() const
	{
		TextFormatter formatter;
		return formatter.format("File: '", mFile, "' is NOT found.");
	}	
}