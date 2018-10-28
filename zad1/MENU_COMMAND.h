#pragma once
#include "MENUITEM.h"
#include "COMMAND.h"


class MENU_COMMAND :
	public MENUITEM
{
public:
	MENU_COMMAND();
	MENU_COMMAND(std::string, std::string, COMMAND*);
	~MENU_COMMAND();
	void Run();
protected:
	COMMAND* command_new;
};

