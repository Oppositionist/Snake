#pragma once
#include <string>
#include <iostream>
#include "Console.h"
#include "Coord.hpp"
#include "LevelObjectType.h"
#include "IDrawable.h"
#include "IControl.h"
using namespace csystem;
using namespace geometry;
using namespace draw;

class LevelObject :public IDrawable
{
private:
	Coord _placement;
	LevelObjectType _symbol;
public:

	void SetPlacement(const Coord & c)
	{
		if (_placement.X == c.X && _placement.Y == c.Y)
		{
			return;
		}
		_placement.X = c.X;
		_placement.Y = c.Y;
	}
	void SetSymbol(const LevelObjectType & objectType)
	{
		if (_symbol == objectType)
		{
			return;
		}
		_symbol = objectType;
	}
	Coord GetPlacement()
	{
		return _placement;
	}
	LevelObjectType GetSymbol() 
	{
		return _symbol;
	}
	void Draw() override
	{
		Console::SetForegroundColor(ConsoleColor::White);
		Console::Write((char)_symbol, _placement.X, _placement.Y);
		Console::Reset();
	}
	void Erase()
	{
		Console::Clear(_placement.X, _placement.Y);
	}

	LevelObject()
	{
	}

	~LevelObject()
	{
	}

};

