#pragma once
#include "IConfigurationProvider.h"

#include <map>

using std::map;

namespace Matrix
{
	class ConfigurationProvider : public IConfigurationProvider
	{
	public:
		
		virtual void load() override;

		virtual void save(shared_ptr<IConfiguration> configuration) override;

		virtual bool tryGet(string key, string& value, string defaultValue = "") override;

		virtual IConfigurationProvider& set(string key, string value) override;

		virtual vector<string> getChildKeys(vector<string> earlierKeys, string parentPath, string delimiter) override;

	private:
		map<string, string> mInternalData;
	};

}