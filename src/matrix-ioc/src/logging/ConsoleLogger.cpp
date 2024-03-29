#include "stdafx.h"
#include "logging/ConsoleLogger.h"
#include "logging/LogLevelConverter.h"

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <chrono>



namespace Matrix
{
	using namespace std;
	using namespace std::chrono;


	ConsoleLogger::ConsoleLogger(const std::string & loggerName)
	{
		name = loggerName;
		mCreatedDate = now();

	}

	ConsoleLogger::ConsoleLogger(const ConsoleLogger& logger)
	{
		name = logger.name;
	}

	ConsoleLogger::~ConsoleLogger()
	{
		
	}


	ILogger & ConsoleLogger::log(LogLevel level, std::string message, int eveintId, std::exception* exception, TextFormatter formatter)
	{
		auto text = format(level, message, eveintId, exception, formatter);
				
		cout << wrapText(now()) << wrapText(name) << text << "\n";

		return *this;
	}


	std::string ConsoleLogger::now()
	{
		auto now = system_clock::now();
		auto ms = duration_cast<milliseconds>(now.time_since_epoch()) % 1000;
		auto timer = system_clock::to_time_t(now);

		std::time_t rawtime = std::time(nullptr);
		struct tm timeinfo;
		localtime_s(&timeinfo, &rawtime);

		std::ostringstream stream;
		stream << std::put_time(&timeinfo, "%d-%m-%Y %H:%M:%S"); 
		stream << '.' << std::setfill('0') << std::setw(3) << ms.count();

		return stream.str();
	}

	std::string ConsoleLogger::wrapText(std::string text)
	{
		if (text != "")
			return "[" + text + "] ";
		else
			return "";
	}

}