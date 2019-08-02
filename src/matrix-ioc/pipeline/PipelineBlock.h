#pragma once
#include "IPipelineBlock.h"
#include "ILoggerFactory.h"
#include "ILogger.h"

#include <functional>

using std::function;
using std::string;
using std::shared_ptr;

namespace Matrix
{

	class PipelineBlock : public IPipelineBlock
	{
	public:
		PipelineBlock(function<void(PipelineContext&)>& action, shared_ptr<ILoggerFactory> loggerFactory, string blockName, int blockOrrder = 100);

		~PipelineBlock();

		virtual void process(PipelineContext & context) override;

	private:
		function<void(PipelineContext&)> mAction;
		shared_ptr<ILogger> mLogger;
	};
}

