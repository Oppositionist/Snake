#pragma once
#include "ConsoleColor.h"
#include "CObject.h"
#include <Windows.h>
namespace csystem
{

	class Console
	{
	private:
		static ConsoleColor _highlightColor;
		static ConsoleColor _foregroundColor;
		static void UpdateConsoleTextColors()
		{
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			unsigned short color = _highlightColor * 16 + _foregroundColor;
			SetConsoleTextAttribute(h, color);
		}
		
	public:

		Console()
		{
		}
		static void Write(std::exception & e) 
		{
			std::cout << e.what() << std::endl;
		}
		static void Write(int a)
		{
			std::cout << a;
		}
		static void Write(CObject & co)
		{
			std::cout << co.ToString();
		}
		static void Write(const std::string & str)
		{
			std::cout << str;
		}
		static void WriteLine(std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		static void WriteLine(int a)
		{
			std::cout << a << std::endl;
		}
		static void WriteLine(CObject & co)
		{
			std::cout << co.ToString() << std::endl;
		}
		static void WriteLine(const std::string & str)
		{
			std::cout << str << std::endl;
		}
		static void SetHighlightColor(const ConsoleColor & bcol)
		{
			if (_highlightColor != bcol)
			{
				_highlightColor = bcol;
				UpdateConsoleTextColors();
			}
		}
		static void SetForegroundColor(const ConsoleColor & fcol)
		{
			if (_foregroundColor != fcol)
			{
				_foregroundColor = fcol;
				UpdateConsoleTextColors();
			}
		}
		static void Clear()
		{
			system ("cls");
		}
		static void SetCursorPosition(int column, int line)
		{
			COORD c;
			c.X = column;
			c.Y = line;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
		}
		static void SetCursorPosition(COORD coo)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coo);
		}
		static void Clear(int column, int line)
		{
			COORD coo = GetCursorPosition();
			SetCursorPosition(column, line);
			std::cout << ' ';
			SetCursorPosition(coo);
		}
		static void Write(char c, int column, int line)
		{
			COORD coo = GetCursorPosition();
			SetCursorPosition(column, line);
			std::cout << c;
			SetCursorPosition(coo);
		}
		static void Write(const std::string & str, int column, int line)
		{
			COORD coo = GetCursorPosition();
			SetCursorPosition(column, line);
			std::cout << str;
			SetCursorPosition(coo);
		}
		static COORD GetCursorPosition()
		{
			CONSOLE_SCREEN_BUFFER_INFO csbi;
			if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
			{
				throw std::bad_exception();
			}
			return csbi.dwCursorPosition;
		}
		static void Reset()
		{
			_highlightColor = ConsoleColor::Black;
			_foregroundColor = ConsoleColor::White;
			UpdateConsoleTextColors();
		}
		~Console()
		{
		}
	};
	ConsoleColor Console::_highlightColor = ConsoleColor::Black;
	ConsoleColor Console::_foregroundColor = ConsoleColor::White;
}; 
