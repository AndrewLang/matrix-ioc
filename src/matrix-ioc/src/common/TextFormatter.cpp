// #include "stdafx.h"
#include "common/TextFormatter.h"

namespace Matrix
{
	TextFormatter & TextFormatter::DefaultTextFormatter()
	{
		static TextFormatter formatter;
		return formatter;
	}

}