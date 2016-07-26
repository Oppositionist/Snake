#pragma once
#include "SignalArgs.h"

template <typename T>
class PropertyChangedSignalArgs :
	public SignalArgs
{
private:
	T _newValue;
	T _oldValue;
public:

	PropertyChangedSignalArgs(T oldValue, T newValue) : _oldValue(oldValue), _newValue(newValue)
	{
	}

	~PropertyChangedSignalArgs()
	{
	}

	T GetNewValue()
	{
		return _newValue;
	}
	T GetOldValue()
	{
		return _oldValue;
	}
};

