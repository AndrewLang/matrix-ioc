#pragma once
#include <vector>
#include <memory>
#include <map>
#include <any>
#include <sstream>
#include <string>

#include "../common/StringExtensions.h"

using std::shared_ptr;
using std::vector;
using std::string;
using std::map;
using std::any;

namespace Matrix
{
	class IConfigurationSection;

	static const char ConfigureKeyDelimiter = ':';

	template<typename TReturn>
	string convertToString(const string & value)
	{
		return value;
	}

	template<typename TReturn>
	TReturn convertTo(const string & value)
	{
		std::istringstream stream(value);
		TReturn target;
				
		if (typeid(TReturn) == typeid(string))
		{						
			for (int i = 0; i < StringExtensions::split(value).size(); i++)
			{
				TReturn tempValue;
				stream >> tempValue;
				if (i > 0)
					target += ' ';
				target += tempValue ;				
			}		}
		else
		{
			stream >> target;
		}

		return target;
	}

	template<typename TReturn>
	string toString(TReturn value)
	{
		std::ostringstream stream;
		stream << value;
		return stream.str();
	}


	class IConfiguration
	{
	public:

		virtual bool tryGet(string key, string& value, string defaultValue = "") = 0;

		virtual IConfiguration& set(string key, string value) = 0;

		template<typename TReturn>
		IConfiguration& setProperty(string name, TReturn value)
		{
			auto stringValue = toString<TReturn>(value);
			set(name, stringValue);

			return *this;
		}

		template<typename TReturn>
		TReturn getProperty(string key, TReturn defaultValue = TReturn())
		{
			string value;
			if (tryGet(key, value))
			{
				return convertTo<TReturn>(value);
			}
			return defaultValue;
		}
	};

}