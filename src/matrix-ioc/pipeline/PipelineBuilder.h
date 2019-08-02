#pragma once
#include "IPipelineBuilder.h"
#include "IServiceProvider.h"

#include <vector>

using std::vector;

namespace Matrix
{
	class PipelineBuilder : public IPipelineBuilder
	{
	public:
		PipelineBuilder(shared_ptr<IServiceProvider> serviceProvider);

		~PipelineBuilder();

		virtual shared_ptr<IPipeline> build() override;

		virtual IPipelineBuilder& use(shared_ptr<IPipelineBlock> block) override;

		virtual IPipelineBuilder& use(std::function<void(PipelineContext&)> action, std::string name = "") override;

		vector<shared_ptr<IPipelineBlock>> getBlocks() const;
		
	private:
		vector<shared_ptr<IPipelineBlock>> mBlocks;

		shared_ptr<IServiceProvider> mServiceProvider;
	};

}