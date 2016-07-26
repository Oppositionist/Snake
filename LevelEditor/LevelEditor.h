#pragma once

#include <conio.h>
#include "Key.h"
#include "Level.hpp"
#include "LevelObject.hpp"

class LevelEditor
{
public:
	
	LevelEditor() {}
	~LevelEditor() {}

	Level lev;

	void Loop()
	{
		for (;;)
		{
			if (_kbhit())
			{
				int key = _getch();

				switch (key)
				{
				case (Key::Esc) :
				{
					return;
					break;
				}
				case (Key::Space) :
				{
					COORD c = Console::GetCursorPosition();
					Coord coo (c.X, c.Y);
					
					LevelObject lo;
					lo.SetPlacement(coo);
					lo.SetSymbol(Wall);

					PtrLevelObject shPtr(new LevelObject(lo));
					
					lev.AddLevelObject(shPtr);
					
					break;
				}
				case (Key::a) :
				{
					COORD c = Console::GetCursorPosition();
					Coord coo(c.X, c.Y);

					LevelObject lo;
					lo.SetPlacement(coo);
					lo.SetSymbol(Apple);

					PtrLevelObject shPtr (new LevelObject(lo));

					lev.AddLevelObject(shPtr);

					break;
				}
				case (Key::b) :
				{
					COORD c = Console::GetCursorPosition();
					Coord coo(c.X, c.Y);

					LevelObject lo;
					lo.SetPlacement(coo);
					lo.SetSymbol(SnakeBody);

					PtrLevelObject shPtr(new LevelObject(lo));

					lev.AddLevelObject(shPtr);

					break;
				}
				case (Key::h) :
				{
					COORD c = Console::GetCursorPosition();
					Coord coo(c.X, c.Y);

					LevelObject lo;
					lo.SetPlacement(coo);
					lo.SetSymbol(SnakeHead);

					PtrLevelObject shPtr(new LevelObject(lo));

					lev.AddLevelObject(shPtr);

					break;
				}
				case (Key::Right) :
				{
					COORD c = Console::GetCursorPosition();
					c.X++;
					Console::SetCursorPosition(c);
					break;
				}
				case (Key::Left) :
				{
					COORD c = Console::GetCursorPosition();
					if (c.X > 0)
					{
						c.X--;
					}
					Console::SetCursorPosition(c);
					break;
				}
				case (Key::Down) :
				{
					COORD c = Console::GetCursorPosition();
					c.Y++;
					Console::SetCursorPosition(c);
					break;
				}
				case (Key::Up) :
				{
					COORD c = Console::GetCursorPosition();
					if (c.Y > 0)
					{
						c.Y--;
					}
					Console::SetCursorPosition(c);
					break;
				}
				case (Key::s) :
				{
					Console::Clear();
					std::string name = std::string();
					std::cout << "SAVE: Please enter a valid file name: ";
					std::cin >> name;
					lev.SetName(name);
					lev.Save();
					Console::Clear();
					lev.Draw();
					
					break;
				}
				case (Key::l) :
				{
					Console::Clear();
					std::string name = std::string();
					std::cout << "LOAD: Please enter a valid file name: ";
					//getline(std::cin, name);
					std::cin >> name;
					if (!(lev.Load(name)))
					{
						std::cout << "Error loading file\n";
						system("pause");
					}
					Console::Clear();
					lev.Draw();
					break;
				}
				}
			}
		}
	}

		//на b будет добавляться тело,
		//на h голова
		//на a яблоко
		/*на s сделай стирание всей консоли и вывод на экран "введите название уровня:"
		и затем устанавливай имя у_level
		затем вызывай _level.save();
		и затем выводи в консоль уровень
		_level.draw()*/
};

