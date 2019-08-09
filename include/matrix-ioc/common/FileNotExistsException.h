#pragma once
#include "BaseException.h"

namespace Matrix
{

	class FileNotExistsException : public BaseException
	{
	public:
		FileNotExistsException(const string& file);

	protected:
		string buildMessage() const override;

	private:
		const string mFile;
	};

}