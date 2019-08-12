#pragma once
#include <functional>
#include <string>
#include <future>
#include <chrono>


namespace Matrix
{
	template<class TReturn, class TFunction>
	class DoWithResult
	{
	public:

		DoWithResult(TFunction func): mFunc(func) { }
		
		DoWithResult<TReturn, TFunction> sleep(int milliseconds);

		DoWithResult<TReturn, TFunction> attempt(int count);

		template<class... TArgs>
		TReturn start(TArgs&&... args)
		{
			TReturn result;
			int count = 0;

			while (count < mTryCount)
			{
				try
				{
					result = mFunc(args...);
					break;
				}
				catch (...)
				{
					count++;
					std::chrono::duration<int, std::milli> delay = std::chrono::milliseconds(mMilliseconds);
					std::this_thread::sleep_for(delay);
				}
			}

			return result;
		}

	private :
		TFunction mFunc;
		int mMilliseconds = 1000;
		int mTryCount = 10;
	};	

	template<class TReturn, class TFunction>
	inline DoWithResult<TReturn, TFunction> DoWithResult<TReturn, TFunction>::sleep(int milliseconds)
	{
		mMilliseconds = milliseconds;
		return *this;
	}

	template<class TReturn, class TFunction>
	inline DoWithResult<TReturn, TFunction> DoWithResult<TReturn, TFunction>::attempt(int count)
	{
		mTryCount = count;
		return *this;
	}
			
}