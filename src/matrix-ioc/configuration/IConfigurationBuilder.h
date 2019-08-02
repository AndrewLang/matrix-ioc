#pragma once
#include <memory>

#include "IConfigurationProvider.h"
#include "IConfigurationRoot.h"

using std::shared_ptr;
using std::vector;

namespace Matrix
{
	class IConfigurationBuilder
	{
	public:
		virtual IConfigurationBuilder& add(shared_ptr<IConfigurationProvider> provider) = 0;

		virtual shared_ptr<IConfigurationRoot> build() = 0;

		virtual vector<shared_ptr<IConfigurationProvider>> getProviders() = 0;

		template<class TProvider, class ... TArgs>
		IConfigurationBuilder& useProvider(TArgs&&... args)
		{
			auto provider = std::make_shared<TProvider>(args...);
			add(provider);
			return *this;
		}
	};
}