#include "TestFiles.h"
#include "platformCheckMacros.h"
#include <filesystem>

namespace fs = std::filesystem;

#if defined(PLATFORM_OS_WINDOWS)
#define SLN_PATH "..\\..\\"
#define Separator "\\"
#elif defined(PLATFORM_OS_LINUX)
#define SLN_PATH "../../../../"
#define Separator "/"
#else
// #error not supported
#endif

string TestFiles::getConfiguration()
{
	return getFilePath("configuration.ini");
}

string TestFiles::get9030A()
{
	return getFilePath("IoMS9030A.ini");
}

string TestFiles::getSimulate()
{
	return getFilePath("PxiSimulate.ini");
}

string TestFiles::getTempFolder()
{
	return ((string)SLN_PATH).append("PxiResourceManagerTests").append(Separator).append("temp").append(Separator);
}

string TestFiles::getCurrentPath()
{
	return fs::current_path().string();
}

string TestFiles::notExistsFile()
{
	return ((string)SLN_PATH).append("PxiResourceManagerTests/files/not-exist.txt");
}

string TestFiles::folder()
{
	return ((string)SLN_PATH).append("PxiResourceManagerTests/files");
}

string TestFiles::notExistsFolder()
{
	return ((string)SLN_PATH).append("PxiResourceManagerTests/files/not-exist");
}

string TestFiles::rootFolder()
{
	return ((string)SLN_PATH).append("PxiResourceManagerTests");
}

string TestFiles::getLockFile()
{
	return ((string)SLN_PATH).append("PxiResourceManagerTests/files/lock.ini" );
}

string TestFiles::getFilePath(string name)
{
	return ((string)SLN_PATH).append("PxiResourceManagerTests/files/" + name);
}
