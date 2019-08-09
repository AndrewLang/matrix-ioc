#pragma once
#include "BaseException.h"

namespace Matrix
{
	class ArgumentNullException : public BaseException
	{
	public:
		ArgumentNullException(const string argument);
		
		string getArgument() const;
	private :
		const string mArgument;

	protected:
		string buildMessage() const override ;
	};
}