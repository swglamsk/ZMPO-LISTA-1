#pragma once
#include "class_temp.h"
class change_length_command :
	public class_temp
{
public:
	change_length_command();
	~change_length_command();
	 void run_command();
};

