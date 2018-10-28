#include "MENU_COMMAND.h"



MENU_COMMAND::MENU_COMMAND()
{

}


MENU_COMMAND::MENU_COMMAND(std::string name, std::string command, COMMAND* cmd)
{
	this->name = name;
	this->command = command;
	this->command_new = cmd;
}

MENU_COMMAND::~MENU_COMMAND()
{
}

void MENU_COMMAND::Run()
{
	this->command_new->run_command();
}


