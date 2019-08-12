#pragma once
#include "IPathResolver.h"

namespace Connectivity
{

	class MockPathResolver : public IPathResolver
	{
	public:
		MockPathResolver();
		~MockPathResolver();

		std::string getFolderPath(SpecialFolders folder) override;

		std::string combine(const std::string& path1, const std::string& path2) override;
	};


}