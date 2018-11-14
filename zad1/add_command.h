#pragma once
#include <string>
#include "class_temp.h"
class add_command :
	public class_temp
{
public:
	add_command();
	~add_command();
	void run_command();
};

