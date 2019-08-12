#include "MockPathResolver.h"

namespace Connectivity
{
	using std::string;


	MockPathResolver::MockPathResolver()
	{
	}


	MockPathResolver::~MockPathResolver()
	{
	}

	string MockPathResolver::getFolderPath(SpecialFolders folder)
	{
		return "";
	}

	string MockPathResolver::combine(const string & path1, const string & path2)
	{
		return "";
	}

}