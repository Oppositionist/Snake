#pragma once
#include "IDrawable.h"
#include "Console.h"
#include "Rectangle.hpp"
#include "Signal.h"
#include <WinBase.h>
using namespace csystem;
using namespace draw;
using namespace geometry;
namespace controls
{
class IControl :public IDrawable
{
private:
	int _borderThickness=0;
	char _borderChar = 219; //219
	int _width=1;
	int _height=1;
	geometry::Rectangle _rect;
	ConsoleColor _foregroundColor = ConsoleColor::White;
	ConsoleColor _backgroundColor = ConsoleColor::Black;
	ConsoleColor _borderColor = ConsoleColor::White;
public:

	void SetBorderThickness(int setThick)
	{
		if (_borderThickness = setThick)
		{
			_borderThickness = setThick;
		}
	}
	void SetHeight(int setHght)
	{
		if (_height == setHght)
		{
			return;
		}
		_height = setHght;
		UpdateLayout();
	}
	void SetWidth(int setWdth)
	{
		if (_width == setWdth)
		{
			return;
		}
		_width = setWdth;
		UpdateLayout();
	}
	void SetBackgroundColor(const ConsoleColor & bcol)
	{
		if (_backgroundColor == bcol)
		{
			return;
		}
		_backgroundColor = bcol;
	}
	void SetBorderColor(const ConsoleColor & bordcol)
	{
		if (_borderColor == bordcol)
		{
			return;
		}
		_borderColor = bordcol;
	}
	void SetForegroundColor(const ConsoleColor & fcol)
	{
		if (_foregroundColor == fcol)
		{
			return;
		}
		_foregroundColor = fcol;
	}
	void SetBorderChar(const char value)
	{
		if (_borderChar == value)
		{
			return;
		}
		_borderChar = value;
		DrawBorder();
	}
	int GetBorderThickness()
	{
		return _borderThickness;
	}
	int GetHeight()
	{
		return _height;
	}
	int GetWidth()
	{
		return _width;
	}
	char GetBorderChar()
	{
		return _borderChar;
	}
	ConsoleColor GetBackgroundColor()
	{
		return _backgroundColor;
	}
	ConsoleColor GetBorderColor()
	{
		return _borderColor;

	}
	ConsoleColor GetForegroundColor()
	{
		return _foregroundColor;
	}

	void DrawBorder()
	{
		Console::SetForegroundColor(GetBorderColor());
		//Console::SetHighlightColor(GetBorderColor());

		for (int i = 0; i < _borderThickness;i++) //рисуем по горизонт
		{
		for (int x = _rect.TopLeft.X; x <= _rect.TopRight.X; x++)
		{
			Console::Write(_borderChar, x, _rect.TopLeft.Y+i);//+
			Console::Write(_borderChar, x, _rect.BottomLeft.Y - i);//-
		}
		}

		for (int j = 0; j < _borderThickness;j++)
		{
		for (int y = _rect.TopLeft.Y; y <= _rect.BottomRight.Y;  y++)
		{
			Console::Write(_borderChar, _rect.TopLeft.X + j, y);
			Console::Write(_borderChar, _rect.TopRight.X-j, y);
		}
		}
	}

	void DrawBackground()
	{
		geometry::Rectangle _iRect = GetInsideRect();

		Console::SetHighlightColor(GetBackgroundColor());

		for (int i = _iRect.TopLeft.Y; i <= _iRect.BottomLeft.Y; i++) // переход по y
		{
			for (int x = _iRect.TopLeft.X; x <= _iRect.TopRight.X; x++) //прорисовка всего
			{
				Console::Write(' ', x, i);
			}
		}

	}

	virtual void Draw()
	{
		DrawBorder(); 
		DrawBackground();
	}

	virtual void UpdateLayout()
	{
		_rect = Rectangle::GetRectangle(_rect.TopLeft, _width, _height);
	}

	geometry::Rectangle GetInsideRect()
	{
		Coord a(_rect.TopLeft.X + _borderThickness, _rect.TopLeft.Y + _borderThickness);
		Coord b(_rect.BottomRight.X - _borderThickness, _rect.BottomRight.Y - _borderThickness);
		geometry::Rectangle _insRect(a, b);
		return _insRect;
	}

	IControl(const Coord & topLeft)
	{
		_rect = Rectangle::GetRectangle(topLeft, _width, _height);
	}

	IControl() {}

	virtual ~IControl() {}

	Signal<IControl*> clicked;
	void Click()
	{
		clicked.Emit(this);
	}
	
};
};


