#pragma once
#include <string>
#include <sstream>

namespace Matrix
{
	const static std::string SPACE = " ";

	class TextFormatter
	{
	public:
		static TextFormatter& DefaultTextFormatter();
		

		template< typename TReturn >
		std::string format(const TReturn& text)
		{
			std::stringstream stream;
			stream << text << SPACE;
			return stream.str();
		}

		template< typename TReturn, typename ... Args >
		std::string format(const TReturn& first, Args ... args)
		{
			return format(first) + format(args...);
		}
		
	};
}