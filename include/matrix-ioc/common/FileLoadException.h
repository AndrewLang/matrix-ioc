#pragma once
#include "BaseException.h"

namespace Matrix
{
	class FileLoadException : public BaseException
	{
	public:
		FileLoadException(const string fileName);

	protected:
		string buildMessage() const override;

	private: 
		const string mFileName;
	};

}