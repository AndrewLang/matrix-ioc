#pragma once
#include <functional>
#include <string>
#include <future>


namespace Matrix
{
	template<class TReturn, class... TArgs>
	using Func = std::function<TReturn(TArgs&&... args)>;


	template<class TReturn, class TFunction>
	class TaskWithResult
	{
	public:		
		TaskWithResult(TFunction func);

		~TaskWithResult();

		TReturn wait();
		
		template<class...TArgs>
		TaskWithResult<TReturn,TFunction>& start(TArgs&&... args)
		{
			mFuture = async(std::launch::async, mFunction, args...);
			return *this;
		}

		TaskWithResult<TReturn, TFunction>& withName(const std::string & taskName);

		std::string name;

	private:
		TFunction mFunction;
		std::future<TReturn> mFuture;
	};

	template<class TReturn, class TFunction>
	inline TaskWithResult<TReturn, TFunction>::TaskWithResult(TFunction func)		
	{
		mFunction = func;
	}

	template<class TReturn, class TFunction>
	inline TaskWithResult<TReturn, TFunction>::~TaskWithResult()
	{
	}

	template<class TReturn, class TFunction>
	inline TReturn TaskWithResult<TReturn, TFunction>::wait()
	{
		return mFuture.get();
	}

	template<class TReturn, class TFunction>
	inline TaskWithResult<TReturn, TFunction>& TaskWithResult<TReturn, TFunction>::withName(const std::string & taskName)
	{
		name = taskName;
		return *this;
	}
}