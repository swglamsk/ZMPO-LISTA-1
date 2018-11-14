#pragma once
class COMMAND
{
public:
	COMMAND();
	virtual ~COMMAND();
	virtual void run_command() = 0;

};

