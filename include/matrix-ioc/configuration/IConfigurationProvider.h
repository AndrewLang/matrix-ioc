#pragma once
#include <memory>
#include <string>
#include <vector>
#include <any>

using std::shared_ptr;
using std::string;
using std::vector;
using std::any;

namespace Matrix
{
	class IConfiguration;

	class IConfigurationProvider
	{
	public:
		virtual void load() = 0;

		virtual void save(shared_ptr<IConfiguration> configuration) = 0;

		virtual bool tryGet(string key, string& value, string defaultValue = "") = 0;

		virtual IConfigurationProvider& set(string key, string value) = 0;

		virtual vector<string> getChildKeys(vector<string> earlierKeys, string parentPath, string delimiter) = 0;
	};
}