#pragma once
#include <functional>
#include <string>
#include <future>
#include <memory>

using std::function;
using std::string;
using std::future;
using std::async;
using std::shared_ptr;

namespace Connectivity
{
	using Action = function<void()>;

	template<class... TArgs>
	using ActionT = function<void(TArgs&&... args)>;
		
		
	class Task
	{
	public:
		Task(Action action);

		Task(const Task& task);

		~Task();

		static shared_ptr<Task> delay(const long milliseconds, const string & name = "delay");

		static void waitAll(std::initializer_list<Task> tasks);

		static shared_ptr<Task> tryDo(Action action, const int& count = 10, const int& delayInMilliseconds = 1000);

		static shared_ptr<Task> execute(Action action);
		
		Task& start();

		Task& wait();

		Task& withName(const string &  taskName);

		string name;

	private:
		Action mAction;
		future<void> mFuture;
	};
	
}