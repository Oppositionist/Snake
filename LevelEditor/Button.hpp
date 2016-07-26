#pragma once
#include "IDrawable.h"
#include "Console.h"
#include "Rectangle.hpp"
#include "IControl.h"


using namespace draw;
using namespace geometry;
using namespace csystem;

namespace controls
{
	class Button : public IControl
{
private:
	std::string _text =  std::string();
public:
	void Draw()
	{
		IControl::Draw();
		DrawForeground();
	}
	void SetText(const std::string & str)
	{
		_text = str;
	}

	void DrawForeground()
	{

		Console::SetForegroundColor(GetForegroundColor());
		Console::SetHighlightColor(GetBackgroundColor()); 

		geometry::Rectangle _tRect = GetInsideRect();
		int centreY = (_tRect.TopRight.Y + _tRect.BottomRight.Y) / 2;
		int tLength = _tRect.TopRight.X - _tRect.TopLeft.X +1;
		int margin = (tLength - _text.length()) / 2;
	
		if (_text.length() <= tLength)
		{ 
			Console::Write(_text, _tRect.TopLeft.X + margin, centreY);
		}
		else 
		{
			_text.resize(tLength);
			Console::Write(_text, _tRect.TopLeft.X, centreY);
		}

		//std::cout << _text;
	}

	Button(const geometry::Coord & topLeft) : IControl(topLeft)
	{
		//_rect = Rectangle::GetRectangle(topLeft, _width, _height);
	}

	Button() {}
	~Button()
	{
	}



};
};
