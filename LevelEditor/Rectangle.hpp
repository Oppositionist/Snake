#pragma once
#include "Coord.hpp"
namespace geometry
{ 
class Rectangle  
{
public:

	Coord TopLeft;
	Coord TopRight;
	Coord BottomLeft;
	Coord BottomRight;

	Rectangle() : TopLeft(0, 0), TopRight(0, 0), BottomLeft(0, 0), BottomRight(0, 0)
	{}

	Rectangle(const Coord& topLeft, const Coord& bottomRight)
	{
		TopLeft = topLeft;
		BottomRight = bottomRight;
		TopRight = Coord(bottomRight.X, topLeft.Y);
		BottomLeft = Coord(topLeft.X, bottomRight.Y);
	}

	static Rectangle GetRectangle(const Coord& topLeft, const int& width, const int& height)
	{
		Coord bottomRight = Coord(topLeft.X + width - 1, topLeft.Y + height - 1);
		return Rectangle(topLeft, bottomRight);
	}
};
};
