#pragma once
#include "IApplicationBuilder.h"

namespace Matrix
{
	class ApplicationBuilder : public IApplicationBuilder
	{
	public:
		ApplicationBuilder();

		~ApplicationBuilder();

		virtual vector<shared_ptr<IComponent>>& getComponents() override;

		virtual vector<shared_ptr<IApplicationStartBlock>>& getBlocks() override;

	protected:
		virtual IApplicationBuilder& registerComponent(shared_ptr<IComponent> component) override;

		virtual IApplicationBuilder& registerStartBlock(shared_ptr<IApplicationStartBlock> block) override;

		
	private:
		vector<shared_ptr<IComponent>> mComponents;
		vector<shared_ptr<IApplicationStartBlock>> mBlocks;
	};


}