#include "stdafx.h"
#include "TextFormatter.h"

namespace Matrix
{
	TextFormatter & TextFormatter::DefaultTextFormatter()
	{
		static TextFormatter formatter;
		return formatter;
	}

}