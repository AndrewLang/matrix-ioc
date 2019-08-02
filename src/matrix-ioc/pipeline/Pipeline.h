#pragma once
#include "IPipeline.h"
#include "IPipelineBlock.h"
#include "ILoggerFactory.h"
#include "ILogger.h"

#include <vector>

using std::vector;

namespace Matrix
{
	class Pipeline : public IPipeline
	{
	public:
		Pipeline(vector<shared_ptr<IPipelineBlock>> blocks, shared_ptr<ILoggerFactory> loggerFactory);

		virtual void process(PipelineContext& context) override;
	private:
		vector<shared_ptr<IPipelineBlock>> mBlocks;
		shared_ptr<ILogger> mLogger;
	};

}