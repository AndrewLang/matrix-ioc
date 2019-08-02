#pragma once


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

using std::vector;
using std::string;
using std::wstring;
using std::set;
using std::chrono::system_clock;

namespace Matrix
{
	class StringExtensions
	{
	public:
		const static int Padding = 25;
		const static char PaddingChar = ' ';
		const static string NewLine;

		static vector<string> split(const string& value, const char& delimiter = ' ')
		{
			vector<string> result;

			std::stringstream stream(value);
			string segment;
			while (std::getline(stream, segment, delimiter))
			{
				result.push_back(segment);
			}
			return result;
		}

		static vector<string> split( const string& value , const string delimiters)
		{
			vector<string> result;

			std::function isDelimiter = [](const string& delimiters, char c)
			{
				for (auto cValue : delimiters)
				{
					if (cValue == c)
						return true;
				}
				return false;
			};

			std::stringstream stringStream(value);
			string word; 
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
		
		static string replace(const string& original, const string& toBeReplace, const string& value)
		{
			string result = original;
			size_t pos = result.find(toBeReplace);

			while (pos != string::npos)
			{
				result.replace(pos, toBeReplace.size(), value);
				pos = result.find(toBeReplace, pos + value.size());
			}
			return result;
		}

		static bool compareIgnoreCase(const string& first, const string& second)
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

		static bool isNullOrEmpty(const string& value)
		{
			return value.length() <= 0;
		}

		static int indexOf(const string& text, const char& value)
		{
			return static_cast<int>(text.find_first_of(value, 0));
		}

		static int indexOf(const string& text, const string& value)
		{
			return static_cast<int>(text.find(value, 0));
		}

		static string textBetween(const string& text, const char& start, const char& end)
		{
			int startIndex = indexOf(text, start);
			int endIndex = indexOf(text, end);
			return text.substr(startIndex + 1, endIndex - startIndex - 1);
		}

		static string literalString(const string& value)
		{
			if (isNullOrEmpty(value))
				return value;

			return replace(value, "\\", R"(\\)");
		}

		static string toLower(const string& value)
		{
			if (isNullOrEmpty(value))
				return value;

			string literal = value;// literalString(value);
			string result;
			result.resize(literal.size());
			std::transform(literal.begin(), literal.end(), result.begin(), [](unsigned char c) {
				return std::tolower(c);
			});

			return result;
		}

		static string toUpper(const string& value)
		{
			if (isNullOrEmpty(value))
				return value;

			string result;
			result.resize(value.size());
			std::transform(value.begin(), value.end(), result.begin(), [](unsigned char c) {
				return std::toupper(c);
			});

			return result;
		}

		static int parseHex(const string& value)
		{
			std::stringstream stream;
			stream << std::hex << value;
		
			int result;
			stream >> result;
			return result;
		}

		template<typename TReturn>
		static TReturn convertTo(const string & value)
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
					target += tempValue;
				}
			}
			else
			{
				stream >> target;
			}

			return target;
		}

		static wstring toWString(const string& value)
		{
			std::wstringstream stream;
			stream << value.c_str();
			return stream.str();
		}

		static string toString(const wstring& value)
		{
			string result(value.begin(), value.end());
			return result;
		}

		static bool endsWith(const string& full, const string& end)
		{
			if (full.length() >= end.length()) {
				return (0 == full.compare(full.length() - end.length(), end.length(), end));
			}
			else {
				return false;
			}
		}

		static bool endsWith(const string& full, const char& end)
		{
			return endsWith(full, string(1, end));
		}

		static bool startsWith(const string& full, const string& start)
		{
			if (full.length() >= start.length()) {
				return std::equal(start.begin(), start.end(), full.begin());				
			}
			else {
				return false;
			}
		}

		static bool startsWith(const string& full, const char& start)
		{
			return startsWith(full, string(1, start));
		}

		static string paddingString(const string& value, const char& paddingChar = PaddingChar, const int& padding = Padding)
		{
			std::stringstream stream;
			stream << std::left << std::setfill(paddingChar) << std::setw(padding) << value;

			return stream.str();
		}

		static string wrapBySquare(const string& value)
		{
			return "[" + value + "]";
		}

		static string getTimestamp()
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