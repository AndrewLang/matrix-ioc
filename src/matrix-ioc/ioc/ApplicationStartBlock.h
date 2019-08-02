#pragma once
#include "IApplicationStartBlock.h"
#include "ILoggerFactory.h"
#include "ILogger.h"

#include <functional>

using std::function;
using std::string;
using std::shared_ptr;

namespace Matrix
{
	class ApplicationStartBlock: public IApplicationStartBlock
	{
	public:
		ApplicationStartBlock(function<void(ApplicationStartBlockContext&)>& action, shared_ptr<ILoggerFactory> loggerFactory, string blockName, int blockOrrder);
		
		~ApplicationStartBlock();

		virtual void process(ApplicationStartBlockContext & context) override;

		virtual void process(PipelineContext & context) override;

	private:
		function<void(ApplicationStartBlockContext&)> mAction;
		shared_ptr<ILogger> mLogger;
	};

}