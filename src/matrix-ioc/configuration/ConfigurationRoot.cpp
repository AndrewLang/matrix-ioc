#include "stdafx.h"
#include "ConfigurationRoot.h"

#include <vector>
#include <set>

namespace Matrix
{
	ConfigurationRoot::ConfigurationRoot(std::vector<std::shared_ptr<IConfigurationProvider>> providers)
		: mProviders(providers)
	{
	}

	ConfigurationRoot::~ConfigurationRoot()
	{
	}

	void ConfigurationRoot::reload()
	{
		for (auto provider : mProviders)
		{
			provider->load();
		}
	}

	void ConfigurationRoot::save()
	{
		for (auto provider : mProviders)
		{
			provider->save(shared_from_this());
		}
	}
	bool ConfigurationRoot::tryGet(std::string key, std::string & value, std::string defaultValue)
	{
		for (auto provider : mProviders)
		{
			if (provider->tryGet(key, value, defaultValue))
			{
				return true;
			}
		}

		return false;
	}
	IConfiguration & ConfigurationRoot::set(std::string key, std::string value)
	{
		for (auto provider : mProviders)
		{
			provider->set(key, value);
		}

		return *this;
	}
}