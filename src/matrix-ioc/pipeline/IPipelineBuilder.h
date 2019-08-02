#pragma once
#include "PipelineContext.h"
#include "IPipeline.h"
#include "IPipelineBlock.h"
#include "../common/ObjectMap.h"

#include <functional>

using std::function;
using std::string;
using std::shared_ptr;

namespace Matrix
{
	class IPipelineBuilder
	{
	public:
		virtual shared_ptr<IPipeline> build() = 0;

		virtual IPipelineBuilder& use(shared_ptr<IPipelineBlock> block) = 0;

		virtual IPipelineBuilder& use(function<void(PipelineContext&)> action, string name = "") = 0;

		template<typename TReturn>
		IPipelineBuilder& useProperty(string name, TReturn value)
		{
			mProperties.add<TReturn>(name, value);
			return *this;
		}

	private:
		ObjectMap<string> mProperties;
	};
}