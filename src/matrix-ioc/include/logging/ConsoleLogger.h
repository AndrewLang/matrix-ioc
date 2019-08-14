#pragma once
#include "../../stdafx.h"

#include "LoggerBase.h"

namespace Matrix
{
	class ConsoleLogger :public LoggerBase
	{
	public:
		ILogger& log(LogLevel level, std::string message, int eveintId, std::exception* exception, TextFormatter formatter) override;

		ConsoleLogger() = delete;

		ConsoleLogger(const std::string & name);

		ConsoleLogger(const ConsoleLogger& logger);

		~ConsoleLogger();
	private:
		std::string mCreatedDate;

		std::string now();
		std::string wrapText(std::string text);
	};

}