#pragma once
#include "IComponent.h"
#include "../configuration/IConfiguration.h"
#include "IApplicationStartBlock.h"

#include <memory>

using std::shared_ptr;
using std::vector;
using std::make_shared;
using std::static_pointer_cast;

namespace Matrix
{
	class IApplication
	{
	public:
		virtual shared_ptr<IConfiguration> initializeConfiguration() = 0;

		virtual IApplication& initializeComponents() = 0;

		virtual IApplication& initializeServices() = 0;

		virtual IApplication& start() = 0;

		virtual IApplication& tearDown() = 0;

		virtual IApplication& registerComponent(shared_ptr<IComponent> component) = 0;

		virtual IApplication& registerStartBlock(shared_ptr<IApplicationStartBlock> block) = 0;

		virtual shared_ptr<IServiceContainer> getServiceContainer() = 0;

		virtual vector<shared_ptr<IComponent>> getComponents() = 0;

		template<class TReturn>
		IApplication& useComponent()
		{
			registerComponent(static_pointer_cast<IComponent>(make_shared<TReturn>()));
			return *this;
		}

		template<class TReturn, class... TArgs>
		IApplication& useComponent(TArgs&&... args)
		{
			registerComponent(static_pointer_cast<IComponent>(make_shared<TReturn>(args)));
			return *this;
		}
	};
}