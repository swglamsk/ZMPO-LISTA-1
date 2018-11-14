#include "MENU.h"
#include <iostream>
#include <vector>
#include <cstdio>


MENU::MENU()
{
	this->name = "Menu glowne";
	this->command = "menu";
}



MENU::~MENU()
{
	for (MENUITEM* obj : menuItems) {
		delete obj;
	}
	menuItems.clear();
	std::cout << "Wyczyszczono" << std::endl;
}

void MENU::Run()
{
	while (true)
	{
		std::cout << this->name << '(' << this->command << ')' << std::endl;
		for (auto menuItem : MENU::menuItems)
		{
			std::cout << menuItem->name << '(' << menuItem->command << ')' << std::endl;
		}
		std::string inputCommand;
		std::cin >> inputCommand;
		if (inputCommand == "back") 
			return;
		bool doesCommandExist = false;
		for (auto menuItem : MENU::menuItems) 
		{
			if (menuItem->command == inputCommand)
			{
				doesCommandExist = true;
				menuItem->Run();
			}
		}
		if (doesCommandExist == false)
			std::cout << "nie ma takiej pozycji" << std::endl;
	}
}

void MENU::addMenuItem(MENUITEM * mi)
{
	for (auto menuItem : MENU::menuItems) {
		if (menuItem->command == mi->command) {
			std::cout << "Istnieje juz komenda " << menuItem->name << ", komendy nie dodano" << std::endl;
			return;
		}
	}
	menuItems.push_back(mi);
}
void MENU::deleteMenuItem(std::string inputCommandName) {
	int i = 0;
	for (auto menuItem : MENU::menuItems) {
		if (menuItem->command == inputCommandName) {
			menuItems.erase(menuItems.begin() + i);
			return;
		}
		i++;
	}
	std::cout << "Nie odnaleziono elementu o podanej komendzie" << std::endl;
}
std::ostream& operator<<(std::ostream& os, const MENU& mn)
{
	os << mn.name << "(" << mn.command << ")";
	return os;
}
