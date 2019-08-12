#include "gtest/gtest.h"
#include "TypeInfo.h"

namespace Connectivity
{
	TEST(TypeInfoTests, Constructor) {
		TypeInfo info(&typeid(int));

		auto expect = &typeid(int);

		ASSERT_EQ(expect, info.rawType);
		ASSERT_EQ("int", info.name);
	}

	TEST(TypeInfoTests, FromGeneric) {
		auto info = TypeInfo::From<int>();

		auto expect = &typeid(int);

		ASSERT_EQ(expect, info->rawType);
		ASSERT_EQ("int", info->name);
	}

	TEST(TypeInfoTests, EqualsOperation) {
		TypeInfo info = &typeid(int);

		auto expect = &typeid(int);

		ASSERT_EQ(expect, info.rawType);
		ASSERT_EQ("int", info.name);
	}
}