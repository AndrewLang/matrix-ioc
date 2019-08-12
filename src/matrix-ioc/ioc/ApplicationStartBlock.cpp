#include "stdafx.h"
#include "ApplicationStartBlock.h"

namespace Matrix
{
	using std::shared_ptr;
	using std::function;
	using std::string;

	ApplicationStartBlock::ApplicationStartBlock(function<void(ApplicationStartBlockContext&)>& action, shared_ptr<ILoggerFactory> loggerFactory, string blockName, int blockOrrder)
		: mAction(action)
	{
		name = blockName;
		order = blockOrrder;
		mLogger = loggerFactory->createLogger("ApplicationStartBlock " + blockName);
	}
	
	ApplicationStartBlock::~ApplicationStartBlock()
	{
	}

	void ApplicationStartBlock::process(ApplicationStartBlockContext & context)
	{
		if (mAction)
		{
			try
			{
				mLogger->debug("Invoking block: ", name);

				mAction(context);
			}
			catch (const std::exception & e)
			{
				context.abort();

				mLogger->debug("Invoking block '", name, "' with exception: ", e.what());
			}
		}
	}

	void ApplicationStartBlock::process(PipelineContext & context)
	{
		if (mAction)
		{
			try
			{
				mLogger->debug("Invoking block: ", name);

				// mAction(context);
			}
			catch (const std::exception & e)
			{
				context.abort();

				mLogger->debug("Invoking block '", name, "' with exception: ", e.what());
			}
		}
	}
}
