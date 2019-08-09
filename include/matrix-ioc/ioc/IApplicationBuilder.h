#pragma once
#include "IApplication.h"

#include <memory>

using std::shared_ptr;

namespace Matrix
{
	class IApplicationBuilder
	{
	public:
		template<class TReturn, class... TArgs>
		shared_ptr<IApplication> build(TArgs&&... args)
		{
			auto app = make_shared<TReturn>(args...);
			for (auto component : getComponents())
			{
				app->registerComponent(component);
			}

			for (auto block : getBlocks())
			{
				app->registerStartBlock(block);
			}
			return app;
		}

		
		template<class TReturn>
		IApplicationBuilder& useComponent()
		{
			registerComponent(static_pointer_cast<IComponent>(make_shared<TReturn>()));
			return *this;
		}

		template<class TReturn, class... TArgs>
		IApplicationBuilder& useComponent(TArgs&&... args)
		{
			registerComponent(static_pointer_cast<IComponent>(make_shared<TReturn>(args...)));
			return *this;
		}
		
		template<class TReturn, class... TArgs>
		IApplicationBuilder& useBlock(TArgs&&... args)
		{
			registerStartBlock(make_shared<TReturn>(args...));
			return *this;
		}

		virtual vector<shared_ptr<IComponent>>& getComponents() = 0;

		virtual vector<shared_ptr<IApplicationStartBlock>>& getBlocks() = 0;

	protected:
		virtual IApplicationBuilder& registerComponent(shared_ptr<IComponent> component) = 0;

		virtual IApplicationBuilder& registerStartBlock(shared_ptr<IApplicationStartBlock> block) = 0;

		
	};
}