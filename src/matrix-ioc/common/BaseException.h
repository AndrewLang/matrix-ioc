#pragma once
#include "TextFormatter.h"

#include <exception>
#include <string>

using std::exception;
using std::string;

namespace Matrix
{
	class EXPORT_SYMBOL BaseException : public exception
	{
	public:
		BaseException();
		
		virtual char const * what() const;

	protected:
		virtual string buildMessage() const;
	};

}