#pragma once
#include "IApiHandler.h"

namespace Connectivity
{
	class ApiHandler : public IApiHandler
	{
	public:
		void handle(std::string name) override;
	};

}