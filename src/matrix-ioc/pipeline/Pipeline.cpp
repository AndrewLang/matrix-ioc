
#include "Pipeline.h"
#include "../common/Guard.h"

#include <iostream>
#include <algorithm>

namespace Matrix
{
	Pipeline::Pipeline(vector<shared_ptr<IPipelineBlock>> blocks, shared_ptr<ILoggerFactory> loggerFactory)
		:mBlocks(blocks) {

		Guard::notNull(loggerFactory, "loggerFactory");

		mLogger = loggerFactory->createLogger("Pipeline");
	}
	
	void Pipeline::process(PipelineContext & context)
	{
		std::sort(mBlocks.begin(), mBlocks.end(), PipelineBlockCompare());

		for (auto block : mBlocks)
		{
			mLogger->debug("Start processing pipeline block: ", block->name);

			block->process(context);

			if (context.isAborted())
			{
				break;
			}

			mLogger->debug("Processed pipeline block: ", block->name);
		}
	}	
}