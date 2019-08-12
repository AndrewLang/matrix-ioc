#pragma once
#include "IComponent.h"

namespace Connectivity
{

	class InitializeComponent : public IComponent
	{
	public:
		InitializeComponent();

		~InitializeComponent();

		void configureServices(std::shared_ptr<IServiceContainer> serviceContainer) override;

		void configure(std::shared_ptr<IServiceProvider> serviceProvider) override;

		void tearDown() override;
	};

}

