#include "Button.hpp"
#include <iostream>
#include <string>
#include "LevelEditor.h"

using namespace controls;

//void allcolours()
//{
//	using namespace std;
//
//	for (int colour = 0x00; colour <= 0xff; colour++)
//	{
//		setconsoletextattribute(getstdhandle(std_output_handle), colour);
//		std::cout << colour << std::endl;
//	}
//}

int main()
{
	//setlocale(LC_ALL, "Russian");

	LevelEditor levEditor;
	levEditor.Loop();

	std::cin.get();
	return 0;
}
