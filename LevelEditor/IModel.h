#pragma once
#include <Signal.h>
template <typename... Args>
class IModel : 
{
public:
	Signal<T, ...Tn> ModelChanged;

	IModel()
	{
	}

	virtual ~IModel()
	{
	}
};

