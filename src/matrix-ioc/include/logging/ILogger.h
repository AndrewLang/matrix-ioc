#pragma once
#include "../stdafx.h"
#include "../common/TextFormatter.h"
#include "../common/StringExtensions.h"
#include "LogMessageName.h"

#include <string>
#include <map>
#include <functional>


namespace Matrix
{
	typedef LogMessageName N;

	enum class LogLevel
	{
		Trace,
		Debug,
		Information,
		Warning,
		Error,
		Fatal,
		None
	};

	class ILogger
	{
	public:
		std::string name;

		virtual bool isEnabled(LogLevel level) = 0;

		virtual ILogger& log(LogLevel level, std::string message, int eveintId = 0, std::exception* exception = nullptr, TextFormatter formatter = TextFormatter::DefaultTextFormatter()) = 0;

		virtual ILogger& debug(std::string message) = 0;

		virtual ILogger& trace(std::string message) = 0;

		virtual ILogger& info(std::string message) = 0;

		virtual ILogger& warning(std::string message) = 0;

		virtual ILogger& error(std::string message) = 0;

		virtual ILogger& fatal(std::string message) = 0;

		ILogger& startGroup(std::string group)
		{
			mGroupName = group;
			return *this;
		}

		ILogger& endGroup()
		{
			debug("End " + mGroupName);
			mGroupName = "";
			return *this;
		}

		template< typename ... Args >
		ILogger& debug(Args ... args)
		{
			if (!mGroupNameLogged && !StringExtensions::isNullOrEmpty(mGroupName))
			{
				debug(mGroupName);
				mGroupNameLogged = true;
			}
			auto message = buildMessage(N(""), args...);
			return debug(message);
		}
		template< typename ... Args >
		ILogger& debug(N name, Args ... args)
		{
			if (!mGroupNameLogged && !StringExtensions::isNullOrEmpty(mGroupName))
			{
				debug(mGroupName);
				mGroupNameLogged = true;
			}

			
			auto message = buildMessage(name, args...);
			return debug(message);
		}

		template< typename ... Args >
		ILogger& trace(Args ... args)
		{
			if (!mGroupNameLogged && !StringExtensions::isNullOrEmpty(mGroupName))
			{
				trace(mGroupName);
				mGroupNameLogged = true;
			}

			auto message = buildMessage(N(""), args...);
			return trace(message);
		}
		template< typename ... Args >
		ILogger& trace(N name, Args ... args)
		{
			if (!mGroupNameLogged && !StringExtensions::isNullOrEmpty(mGroupName))
			{
				trace(mGroupName);
				mGroupNameLogged = true;
			}

			
			auto message = buildMessage(name, args...);
			return trace(message);
		}


		template< typename ... Args >
		ILogger& info(Args ... args)
		{
			if (!mGroupNameLogged && !StringExtensions::isNullOrEmpty(mGroupName))
			{
				info(mGroupName);
				mGroupNameLogged = true;
			}

			auto message = buildMessage(N(""), args...);
			return info(message);
		}
		template< typename ... Args >
		ILogger& info(N name, Args ... args)
		{
			if (!mGroupNameLogged && !StringExtensions::isNullOrEmpty(mGroupName))
			{
				info(mGroupName);
				mGroupNameLogged = true;
			}

			auto message = buildMessage(name, args...);
			return info(message);
		}


		template< typename ... Args >
		ILogger& warning(Args ... args)
		{
			if (!mGroupNameLogged && !StringExtensions::isNullOrEmpty(mGroupName))
			{
				warning(mGroupName);
				mGroupNameLogged = true;
			}

			auto message = buildMessage(N(""), args...);
			return warning(message);
		}
		template< typename ... Args >
		ILogger& warning(N name, Args ... args)
		{
			if (!mGroupNameLogged && !StringExtensions::isNullOrEmpty(mGroupName))
			{
				warning(mGroupName);
				mGroupNameLogged = true;
			}

			auto message = buildMessage(name, args...);
			return warning(message);
		}

		template< typename ... Args >
		ILogger& error(Args ... args)
		{
			if (!mGroupNameLogged && !StringExtensions::isNullOrEmpty(mGroupName))
			{
				error(mGroupName);
				mGroupNameLogged = true;
			}

			auto message = buildMessage(N(""), args...);
			return error(message);
		}
		template< typename ... Args >
		ILogger& error(N name, Args ... args)
		{
			if (!mGroupNameLogged && !StringExtensions::isNullOrEmpty(mGroupName))
			{
				error(mGroupName);
				mGroupNameLogged = true;
			}

			auto message = buildMessage(name, args...);
			return error(message);
		}

		template< typename ... Args >
		ILogger& fatal(Args ... args)
		{
			if (!mGroupNameLogged && !StringExtensions::isNullOrEmpty(mGroupName))
			{
				fatal(mGroupName);
				mGroupNameLogged = true;
			}

			auto message = buildMessage(N(""), args...);
			return fatal(message);
		}
		template< typename ... Args >
		ILogger& fatal(N name, Args ... args)
		{
			if (!mGroupNameLogged && !StringExtensions::isNullOrEmpty(mGroupName))
			{
				fatal(mGroupName);
				mGroupNameLogged = true;
			}

			auto message = buildMessage(name, args...);
			return fatal(message);
		}

	private:
		std::string mGroupName = "";
		bool mGroupNameLogged = false;


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

		template< typename ... Args >
		std::string buildMessage(N name, Args ... args)
		{
			std::string title = StringExtensions::paddingString(name.getName());
			return StringExtensions::isNullOrEmpty(mGroupName) ? format(title, args...) : StringExtensions::Tab + format(title, args...);
		}

	protected:
		

	};
}