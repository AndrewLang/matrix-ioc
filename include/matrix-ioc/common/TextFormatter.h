#pragma once
#include <string>
#include <sstream>

using std::string;

namespace Matrix
{
	const static string SPACE = " ";

	class TextFormatter
	{
	public:
		static TextFormatter& DefaultTextFormatter();
		

		template< typename TReturn >
		string format(const TReturn& text)
		{
			std::stringstream stream;
			stream << text << SPACE;
			return stream.str();
		}

		template< typename TReturn, typename ... Args >
		string format(const TReturn& first, Args ... args)
		{
			return format(first) + format(args...);
		}
		
	};
}