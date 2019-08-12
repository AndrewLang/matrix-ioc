#pragma once
#include "IApplicationStartBlock.h"
#include "../logging/ILoggerFactory.h"
#include "../logging/ILogger.h"

#include <functional>


namespace Matrix
{
	class ApplicationStartBlock: public IApplicationStartBlock
	{
	public:
		ApplicationStartBlock(std::function<void(ApplicationStartBlockContext&)>& action, std::shared_ptr<ILoggerFactory> loggerFactory, std::string blockName, int blockOrrder);
		
		~ApplicationStartBlock();

		virtual void process(ApplicationStartBlockContext & context) override;

		virtual void process(PipelineContext & context) override;

	private:
		std::function<void(ApplicationStartBlockContext&)> mAction;
		std::shared_ptr<ILogger> mLogger;
	};

}