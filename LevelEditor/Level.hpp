#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "Console.h"
#include "Coord.hpp"
#include "LevelObjectType.h"
#include "IDrawable.h"
#include "IControl.h"
#include "LevelObject.hpp"
#include <algorithm>
#include <list>
#include <fstream>
typedef std::shared_ptr<LevelObject> PtrLevelObject;

using namespace csystem;
using namespace geometry;
using namespace draw;

class Level :public IDrawable
{
private:
	std::string _name;
public:

	std::list<PtrLevelObject> walls;
	
	void SetName(const std::string & name)
	{
		if (_name == name)
		{
			return;
		}
		_name = name;
	}

	std::string GetName()
	{
		return _name;
	}

	void AddLevelObject(const PtrLevelObject o)
	{
		bool exist = any_of(walls.begin(), walls.end(), [o](const PtrLevelObject & obj)
		{
			return obj->GetPlacement() == o->GetPlacement();
		});
		if (exist)
		{
			walls.remove_if([o](const PtrLevelObject & obj)
			{
				return o->GetPlacement() == obj->GetPlacement();
			});
			o->Erase();
		}
		else
		{
			walls.push_back(o);
			o->Draw();
		}
	}

	Level()
	{
	}

	void Draw() override
	{
		for (auto obj : walls)
		{
			obj->Draw();
		}
	}

	void Save()
	{
		Coord crd;
		LevelObjectType sym;
		std::ofstream ofile;
		ofile.open((_name+".txt").c_str());
		ofile << _name << "\n";
		for (auto obj : walls)
		{
			crd = obj->GetPlacement();
			sym =  obj->GetSymbol();
			ofile << crd.X << ' ' << crd.Y << ' ' << static_cast<char>(sym) << ' ' << std::endl;
		}
	}
	bool Load(const std::string & fileName)
	{
		Coord crd;
		char sym;
		LevelObject lo;
	
		std::ifstream ifile;
		ifile.open(fileName + ".txt");
		if (!ifile.is_open())
		{
			return false;
		}
		ifile >> _name;
		if (ifile.get() == '\n')
		{
			while (!ifile.eof())
			{
				ifile >> crd.X >> crd.Y >> sym;
				lo.SetPlacement(crd);
				lo.SetSymbol(static_cast<LevelObjectType>(sym));
				PtrLevelObject shPtr(new LevelObject(lo));
				AddLevelObject(shPtr);
				if (ifile.get() == '\n')
				{
					continue;
				}
			}
		}
		return true;
	}

	~Level()
	{
	}
};


