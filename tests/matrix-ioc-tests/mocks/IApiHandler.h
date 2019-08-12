#pragma once
#include <string>

namespace Connectivity
{
	class IApiHandler
	{
	public:
		virtual void handle(std::string name) = 0;
	};

}
