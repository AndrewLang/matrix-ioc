
#include "PipelineContext.h"

namespace Matrix
{
	void PipelineContext::abort()
	{
		mRequestAborted = true;
	}
	bool PipelineContext::isAborted() const
	{
		return mRequestAborted;
	}
}