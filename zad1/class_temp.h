#pragma once
#include "COMMAND.h"
#include "CTABLE.h"
#include <vector>
class class_temp :
	public COMMAND
{
protected:
	int number_of_tables;
	std::vector<CTABLE> array_of_tables;
public:
	class_temp();
	~class_temp();
	 void run_command();
};

