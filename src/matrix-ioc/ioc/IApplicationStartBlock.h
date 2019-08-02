#pragma once
#include "IPipelineBlock.h"
#include "ApplicationStartBlockContext.h"

namespace Matrix
{
	class IApplicationStartBlock : public IPipelineBlock
	{
	public:
		virtual void process(ApplicationStartBlockContext & context) = 0;

	};
}