#pragma once
#include <Windows.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <time.h>
#include <stdio.h>

#include "TextFormatter.h"
#include "StringExtensions.h"

using std::chrono::system_clock;
using std::string;

namespace Matrix
{
	class VsOutput
	{
	public:
		
		template<typename ... Args >
		static void debug(Args&& ... args)
		{
			TextFormatter formatter;
			auto message = formatter.format(args...);

			message = StringExtensions::wrapBySquare(StringExtensions::getTimestamp()) + SPACE + message;

			std::wstring stemp = std::wstring(message.begin(), message.end());
			OutputDebugString(stemp.c_str());
		}

		template<typename ... Args >
		static void debugLine(Args&& ... args)
		{
			TextFormatter formatter;
			auto message = formatter.format(args...);
			message = StringExtensions::wrapBySquare(StringExtensions::getTimestamp()) + SPACE + message + StringExtensions::NewLine;

			std::wstring stemp = std::wstring(message.begin(), message.end());
			OutputDebugString(stemp.c_str());
		}

		template<typename ... Args >
		static void writeWithName(string name, Args&& ... args)
		{			
			TextFormatter formatter;
			auto message = StringExtensions::wrapBySquare(StringExtensions::getTimestamp()) 
				+ SPACE 
				+ StringExtensions::paddingString(name) 
				+ SPACE 
				+ formatter.format(args...) 
				+ StringExtensions::NewLine;

			std::wstring stemp = std::wstring(message.begin(), message.end());
			OutputDebugString(stemp.c_str());
		}

	private:

		
		
	};


}
