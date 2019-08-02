#include "../stdafx.h"
#include "FileLoadException.h"

namespace Matrix
{
	FileLoadException::FileLoadException(const string fileName)
		: mFileName(fileName)
	{
	}

	string FileLoadException::buildMessage() const
	{
		TextFormatter formatter;
		return formatter.format("Load file '", mFileName, "' failed.");
	}
}