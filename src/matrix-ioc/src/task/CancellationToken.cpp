#include "stdafx.h"
#include "task/CancellationToken.h"

namespace Connectivity
{
	CancellationToken::CancellationToken()
	{
	}


	CancellationToken::~CancellationToken()
	{
	}
	bool CancellationToken::isCancellationRequested()
	{
		return false;
	}
	void CancellationToken::cancel()
	{
	}
}
