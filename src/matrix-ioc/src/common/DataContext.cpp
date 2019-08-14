#include "stdafx.h"
#include "ioc/DataContext.h"


namespace Matrix
{
	using std::shared_ptr;

	DataContext::DataContext()
	{
	}

	DataContext::DataContext(shared_ptr<IServiceProvider> serviceProvider)
		:mServiceProvider(serviceProvider)
	{
	}

	DataContext::~DataContext()
	{
	}

	shared_ptr<IServiceProvider> DataContext::services()
	{
		return mServiceProvider;
	}

	DataContext & DataContext::clear()
	{
		mDataContainer.clear();

		return *this;
	}

}