#pragma once
#include <vector>
#include <memory>
#include <map>

#include <sstream>
#include <string>

#include "../common/StringExtensions.h"

namespace Matrix
{
	class IConfigurationSection;

	static const char ConfigureKeyDelimiter = ':';

	template<typename TReturn>
	std::string convertToString(const std::string & value)
	{
		return value;
	}

	template<typename TReturn>
	TReturn convertTo(const std::string & value)
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
	std::string toString(TReturn value)
	{
		std::ostringstream stream;
		stream << value;
		return stream.str();
	}


	class IConfiguration
	{
	public:

		virtual bool tryGet(std::string key, std::string& value, std::string defaultValue = "") = 0;

		virtual IConfiguration& set(std::string key, std::string value) = 0;

		template<typename TReturn>
		IConfiguration& setProperty(std::string name, TReturn value)
		{
			auto stringValue = toString<TReturn>(value);
			set(name, stringValue);

			return *this;
		}

		template<typename TReturn>
		TReturn getProperty(std::string key, TReturn defaultValue = TReturn())
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