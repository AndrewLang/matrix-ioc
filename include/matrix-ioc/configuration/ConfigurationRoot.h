#pragma once
#include "IConfigurationRoot.h"
#include "IConfigurationProvider.h"
#include "IConfigurationSaver.h"

namespace Matrix
{
	class ConfigurationRoot : public IConfigurationRoot
		, public IConfigurationSaver
		, public std::enable_shared_from_this<ConfigurationRoot>
	{
	public:
		ConfigurationRoot(vector<shared_ptr<IConfigurationProvider>> providers);

		~ConfigurationRoot();

		void reload() override;

		void save() override;

		bool tryGet(string key, string& value, string defaultValue = "") override;

		IConfiguration& set(string key, string value) override;

	private:
		vector<shared_ptr<IConfigurationProvider>> mProviders;
	};

}