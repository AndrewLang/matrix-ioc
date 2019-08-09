#pragma once
#include "TextFormatter.h"

#include <exception>
#include <string>

using std::exception;
using std::string;

namespace Matrix
{
	// EXPORT_SYMBOL
	class  BaseException : public exception
	{
	public:
		BaseException();
		
		virtual char const * what() const;

	protected:
		virtual string buildMessage() const;
	};

}