#pragma once
namespace draw
{ 
class IDrawable
{
public:

	IDrawable()
	{
	}

	virtual void Draw() = 0;

	virtual ~IDrawable()
	{
	}
};
};
