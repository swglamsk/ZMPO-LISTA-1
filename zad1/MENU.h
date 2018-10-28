#pragma once
#include "MENUITEM.h"
#include <vector>
class MENU : 
	public MENUITEM
{
public:
	MENU();
	~MENU();
	void Run();
	void addMenuItem(MENUITEM*);
	void deleteMenuItem(std::string);
protected:
	std::vector<MENUITEM*> menuItems;
	MENUITEM * menu;
	std::string type_command;
};

