#pragma once
#include "IConfigurationBuilder.h"

namespace Matrix
{

	class ConfigurationBuilder: public IConfigurationBuilder
	{
	public:
		ConfigurationBuilder();

		~ConfigurationBuilder();

		virtual IConfigurationBuilder& add(shared_ptr<IConfigurationProvider> provider) override;

		virtual shared_ptr<IConfigurationRoot> build() override;

		virtual vector<shared_ptr<IConfigurationProvider>> getProviders() override;

	private:
		vector<shared_ptr<IConfigurationProvider>> mProviders;
	};


}