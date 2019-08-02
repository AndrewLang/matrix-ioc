#pragma once
#include "IApplication.h"
#include "IComponent.h"

#include <memory>

using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::static_pointer_cast;


namespace Matrix
{
	class ApplicationBase : public IApplication, public std::enable_shared_from_this<ApplicationBase>
	{
	public:
		shared_ptr<IConfiguration> initializeConfiguration() override;

		IApplication& initializeComponents() override;

		IApplication& initializeServices() override;

		IApplication& start() override;

		IApplication& tearDown() override;

		IApplication& registerComponent(shared_ptr<IComponent> component) override;

		IApplication& registerStartBlock(shared_ptr<IApplicationStartBlock> block) override;

		std::shared_ptr<IServiceContainer> getServiceContainer() override;

		vector<shared_ptr<IComponent>> getComponents() override;
		
		vector<shared_ptr<IApplicationStartBlock>> getBlocks() const;

		ApplicationBase();

		~ApplicationBase();

	private:
		vector<shared_ptr<IComponent>> mComponents;
		vector<shared_ptr<IApplicationStartBlock>> mBlocks;
		shared_ptr<IServiceContainer> mServiceContainer;

	protected:
		virtual void registerServices(shared_ptr<IServiceContainer> container) = 0;

	};

}
