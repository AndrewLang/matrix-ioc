#pragma once
#include "ConfigurationProvider.h"

namespace Matrix
{
	class FileConfigurationProvider : public ConfigurationProvider
	{
	public:
		string fullPath;
	};
}