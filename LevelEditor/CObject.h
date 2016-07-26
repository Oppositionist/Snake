#pragma once
#include <string>
#include <iostream>
namespace csystem
{ 
class CObject
{
public:

	CObject()
	{
	}

	virtual ~CObject()
	{
	}

	virtual std::string ToString()
	{
		std::string str = "test";//std::string();
		return str;
	}
};
};