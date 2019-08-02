#pragma once
#include "ILogger.h"
#include "LogLevelConverter.h"


namespace Matrix
{
	class LoggerBase :public ILogger
	{
	public:
		LoggerBase();

		~LoggerBase();

		bool isEnabled(LogLevel level) override;

		ILogger& debug(string message) override;

		ILogger& trace(string message) override;

		ILogger& info(string message) override;

		ILogger& warning(string message) override;

		ILogger& error(string message) override;

		ILogger& fatal(string message) override;

	protected:
		std::string format(LogLevel level, std::string message, int eveintId = 0, std::exception* exception = nullptr, TextFormatter formatter = TextFormatter::DefaultTextFormatter());

		LogLevelConverter mConverter;

		string wrapText(string value);
	};

}