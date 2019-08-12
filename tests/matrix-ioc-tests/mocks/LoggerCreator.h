#pragma once
#include "ILoggerFactory.h"
#include "LoggerFactory.h"
#include "VsOutputLoggerProvider.h"

#include <memory>

using std::shared_ptr;

namespace Connectivity
{
	class LoggerCreator
	{
	public:
		LoggerCreator();
		~LoggerCreator();

		static shared_ptr<ILoggerFactory> createFactory()
		{
			auto factory = std::make_shared<LoggerFactory>();

			factory->useProvider<VsOutputLoggerProvider>();

			return factory;
		}
	};

}