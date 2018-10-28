#pragma once
#include <string>
class MENUITEM
{
public:
	std::string command;
	std::string name;
public:
	virtual void Run() = 0;
	virtual ~MENUITEM();
};

