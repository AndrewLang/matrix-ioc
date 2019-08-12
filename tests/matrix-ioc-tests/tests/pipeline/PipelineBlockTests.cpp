#include "gtest/gtest.h"
#include "PipelineBlock.h"
#include "LoggerFactory.h"
#include "PipelineContext.h"

namespace Connectivity
{
	using std::function;
	TEST(PipelineBlockTests, Constructor) {
		function<void(PipelineContext&)> action = [](PipelineContext& context) {};

		auto loggerFactory = std::make_shared<LoggerFactory>();

		PipelineBlock block(action, loggerFactory, "test");

		ASSERT_EQ("test", block.name);
	}

	TEST(PipelineBlockTests, Process) {
		bool actionInvoked = false;

		function<void(PipelineContext&)> action = [&](PipelineContext& context) {
			actionInvoked = true;
			context.setProperty<bool>("started", true);
		};

		auto loggerFactory = std::make_shared<LoggerFactory>();

		PipelineBlock block(action, loggerFactory, "test");

		PipelineContext context;
		context.setProperty<bool>("started", false);
		block.process(context);

		ASSERT_TRUE(actionInvoked);
		ASSERT_TRUE(context.getProperty<bool>("started"));
	}
}