#include "COMMAND.h"
#include <iostream>



COMMAND::COMMAND()
{
}


COMMAND::~COMMAND()
{
}
void COMMAND::run_command()
{
	std::cout << "Default" << std::endl;
}

