#pragma once
#include "../stdafx.h"
#include "TextFormatter.h"

#include <exception>
#include <string>


namespace Matrix
{
	
	class BaseException : public std::exception
	{
	public:
		BaseException();
		
		virtual char const * what() const;

	protected:
		virtual std::string buildMessage() const;
	};

}