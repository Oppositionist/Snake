#pragma once
#include "level.hpp"
#include <list>
#include "MoveDirection.h"
class Snake
{
	std::list<PtrLevelObject> _snakeParts;
public:
	
	void SetSnakeParts()
	{

	}

	std::list<PtrLevelObject> GetSnakeParts()
	{
		return _snakeParts;
	}
	void Move(const MoveDirection & md)
	{

	}

	Snake() = default;
	~Snake() = default;
};

