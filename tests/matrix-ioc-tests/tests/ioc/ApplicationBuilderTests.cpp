#include "gtest/gtest.h"
#include "ApplicationBuilder.h"
#include "ApiHandleComponent.h"
#include "InitializeComponent.h"
#include "ApplicationStartBlock.h"
#include "LoggerFactory.h"
#include "MockApplication.h"

#include <functional>

using std::function;

namespace Connectivity
{
	TEST(ApplicationBuilderTests, Constructor) {
		ApplicationBuilder builder;
	}

	TEST(ApplicationBuilderTests, UseComponent) {
		ApplicationBuilder builder;

		builder
			.useComponent<ApiHandleComponent>()
			.useComponent<InitializeComponent>();

		auto components = builder.getComponents();

		ASSERT_EQ(2, components.size());
	}

	TEST(ApplicationBuilderTests, UseBlock) {
		ApplicationBuilder builder;

		auto factory = std::make_shared<LoggerFactory>();

		function<void(ApplicationStartBlockContext&)> action = [](ApplicationStartBlockContext& context) {};
			

		builder
			.useBlock<ApplicationStartBlock>(action, factory, "block1", 100)
			.useBlock<ApplicationStartBlock>(action, factory, "block2", 200);

		auto blocks = builder.getBlocks();

		ASSERT_EQ(2, blocks.size());
	}

	TEST(ApplicationBuilderTests, Build) {
		ApplicationBuilder builder;
		auto factory = std::make_shared<LoggerFactory>();

		bool invoked = false;
		function<void(ApplicationStartBlockContext&)> action = [&](ApplicationStartBlockContext& context) {
			invoked = true;
		};


		builder
			.useComponent<ApiHandleComponent>()
			.useComponent<InitializeComponent>()
			.useBlock<ApplicationStartBlock>(action, factory, "block1", 100)
			.useBlock<ApplicationStartBlock>(action, factory, "block2", 200);

		ASSERT_EQ(2, builder.getBlocks().size());
		ASSERT_EQ(2, builder.getComponents().size());

		auto app = builder.build<MockApplication>();

		ASSERT_EQ(2, app->getComponents().size());

		app->start();

		ASSERT_TRUE(invoked);
	}
}