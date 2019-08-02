#pragma once
#include <memory>

using std::shared_ptr;

namespace Matrix
{
	class MapValueDescritor
	{
	public:
		shared_ptr<void> value;
	};

}