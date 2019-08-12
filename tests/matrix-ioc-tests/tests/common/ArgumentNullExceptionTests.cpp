#include "gtest/gtest.h"
#include "ArgumentNullException.h"

namespace Connectivity
{
	TEST(ArgumentNullExceptionTests, Constructor) {
		ArgumentNullException exception("test");

		ASSERT_EQ("test", exception.getArgument());
	}

}