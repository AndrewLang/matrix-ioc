#pragma once
#include "../stdafx.h"
#include <Windows.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <time.h>
#include <stdio.h>

#include "../common/TextFormatter.h"
#include "../common/StringExtensions.h"


namespace Matrix
{
	class EXPORT VsOutput
	{
	public:

		template<typename ... Args >
		static void debug(Args&& ... args)
		{
			TextFormatter formatter;
			auto message = formatter.format(args...);

			message = StringExtensions::wrapBySquare(StringExtensions::getTimestamp()) + SPACE + message;

			logMessage(message);
			
		}

		template<typename ... Args >
		static void debugLine(Args&& ... args)
		{
			TextFormatter formatter;
			auto message = formatter.format(args...);
			message = StringExtensions::wrapBySquare(StringExtensions::getTimestamp()) + SPACE + message + StringExtensions::NewLine;

			logMessage(message);
		}

		template<typename ... Args >
		static void writeWithName(std::string name, Args&& ... args)
		{
			TextFormatter formatter;
			auto message = StringExtensions::wrapBySquare(StringExtensions::getTimestamp())
				+ SPACE
				+ StringExtensions::paddingString(name)
				+ SPACE
				+ formatter.format(args...)
				+ StringExtensions::NewLine;

			logMessage(message);
		}

	private:

		inline static void logMessage(std::string message)
		{			
			LPCTSTR lp = message.c_str(); 

			OutputDebugString(lp);
		}
	};	   
}
