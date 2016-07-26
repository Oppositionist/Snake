#pragma once
#include <Windows.h>
#include "Rectangle.hpp"
namespace geometry 
{
class Coord
{
public:
	int X=0;
	int Y=0;
	Coord(int x, int y) : X(x), Y(y)
	{
	}
	Coord() 
	{
	}

	virtual ~Coord()
	{
	}

	bool operator== (const Coord& r) {
		return (this->X == r.X && Y == r.Y);
	}

	operator COORD()
	{
		COORD res;
		X = res.X; 
		Y = res.Y;
		return res;
	}

};
};
