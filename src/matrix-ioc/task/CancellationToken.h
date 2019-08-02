#pragma once

namespace Connectivity
{
	class CancellationToken
	{
	public:
		CancellationToken();

		~CancellationToken();

		bool isCancellationRequested();

		void cancel();
	};
	
}