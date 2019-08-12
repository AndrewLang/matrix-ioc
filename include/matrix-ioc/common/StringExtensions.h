#pragma once
#include "../stdafx.h"

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <locale>
#include <cctype>
#include <algorithm>
#include <set>
#include <functional>
#include <stdio.h>
#include <iomanip>
#include <chrono>


namespace Matrix
{
	class StringExtensions
	{
	public:
		const static int Padding = 25;
		const static char PaddingChar = ' ';
		const static std::string NewLine;
		const static std::string Tab;

		static std::vector<std::string> split(const std::string& value, const char& delimiter = ' ')
		{
			std::vector<std::string> result;

			std::stringstream stream(value);
			std::string segment;
			while (std::getline(stream, segment, delimiter))
			{
				result.push_back(segment);
			}
			return result;
		}

		static std::vector<std::string> split( const std::string& value , const std::string delimiters)
		{
			std::vector<std::string> result;

			std::function<bool(const std::string, char)> isDelimiter = [](const std::string& delimiters, char c)
			{
				for (auto cValue : delimiters)
				{
					if (cValue == c)
						return true;
				}
				return false;
			};

			std::stringstream stringStream(value);
			std::string word; 
			char c;
			

			while (stringStream) {
				word.clear();

				// Read word
				c = stringStream.get();
				while (!isDelimiter(delimiters, c))
				{
					word.push_back(c);
					c = stringStream.get();
					if (c == EOF)
						break;
				}

				result.push_back(word);
			}

			return result;
		}
		
		static std::string replace(const std::string& original, const std::string& toBeReplace, const std::string& value)
		{
			std::string result = original;
			size_t pos = result.find(toBeReplace);

			while (pos != std::string::npos)
			{
				result.replace(pos, toBeReplace.size(), value);
				pos = result.find(toBeReplace, pos + value.size());
			}
			return result;
		}

		static bool compareIgnoreCase(const std::string& first, const std::string& second)
		{
			if (first.length() == second.length())
			{
				return std::equal(second.begin(), second.end(), first.begin(), compareChar);
			}
			else
			{
				return false;
			}
		}

		static bool isNullOrEmpty(const std::string& value)
		{
			return value.length() <= 0;
		}

		static int indexOf(const std::string& text, const char& value)
		{
			return static_cast<int>(text.find_first_of(value, 0));
		}

		static int indexOf(const std::string& text, const std::string& value)
		{
			return static_cast<int>(text.find(value, 0));
		}

		static std::string textBetween(const std::string& text, const char& start, const char& end)
		{
			int startIndex = indexOf(text, start);
			int endIndex = indexOf(text, end);
			return text.substr(startIndex + 1, endIndex - startIndex - 1);
		}

		static std::string literalString(const std::string& value)
		{
			if (isNullOrEmpty(value))
				return value;

			return replace(value, "\\", R"(\\)");
		}

		static std::string toLower(const std::string& value)
		{
			if (isNullOrEmpty(value))
				return value;

			std::string literal = value;// literalstd::string(value);
			std::string result;
			result.resize(literal.size());
			std::transform(literal.begin(), literal.end(), result.begin(), [](unsigned char c) {
				return std::tolower(c);
			});

			return result;
		}

		static std::string toUpper(const std::string& value)
		{
			if (isNullOrEmpty(value))
				return value;

			std::string result;
			result.resize(value.size());
			std::transform(value.begin(), value.end(), result.begin(), [](unsigned char c) {
				return std::toupper(c);
			});

			return result;
		}

		static int parseHex(const std::string& value)
		{
			std::stringstream stream;
			stream << std::hex << value;
		
			int result;
			stream >> result;
			return result;
		}

		template<typename TReturn>
		static TReturn convertTo(const std::string & value)
		{
			std::istd::stringstream stream(value);
			TReturn target;

			if (typeid(TReturn) == typeid(std::string))
			{
				for (int i = 0; i < std::stringExtensions::split(value).size(); i++)
				{
					TReturn tempValue;
					stream >> tempValue;
					if (i > 0)
						target += ' ';
					target += tempValue;
				}
			}
			else
			{
				stream >> target;
			}

			return target;
		}

		static std::wstring toWString(const std::string& value)
		{
			std::wstringstream stream;
			stream << value.c_str();
			return stream.str();
		}

		static std::string toString(const std::wstring& value)
		{
			std::string result(value.begin(), value.end());
			return result;
		}

		static bool endsWith(const std::string& full, const std::string& end)
		{
			if (full.length() >= end.length()) {
				return (0 == full.compare(full.length() - end.length(), end.length(), end));
			}
			else {
				return false;
			}
		}

		static bool endsWith(const std::string& full, const char& end)
		{
			return endsWith(full, std::string(1, end));
		}

		static bool startsWith(const std::string& full, const std::string& start)
		{
			if (full.length() >= start.length()) {
				return std::equal(start.begin(), start.end(), full.begin());				
			}
			else {
				return false;
			}
		}

		static bool startsWith(const std::string& full, const char& start)
		{
			return startsWith(full, std::string(1, start));
		}

		static std::string paddingString(const std::string& value, const char& paddingChar = PaddingChar, const int& padding = Padding)
		{
			std::stringstream stream;
			stream << std::left << std::setfill(paddingChar) << std::setw(padding) << value;

			return stream.str();
		}

		static std::string wrapBySquare(const std::string& value)
		{
			return "[" + value + "]";
		}

		static std::string getTimestamp()
		{
			time_t rawtime;
			struct tm timeinfo;

			time(&rawtime);

			localtime_s(&timeinfo, &rawtime);

			// Must be static, otherwise won't work
			static char result[20];
			strftime(result, sizeof(result), "%Y-%m-%d %H:%M:%S", &timeinfo);

			return result;
		}
	private:
		static bool compareChar(unsigned char first, unsigned char second)
		{
			return std::tolower(first) == std::tolower(second);
		}
	};

}