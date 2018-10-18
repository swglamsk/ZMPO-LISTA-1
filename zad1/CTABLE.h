#pragma once
#include <string>
class CTABLE
{
public:
	static const std::string DEFAULT_NAME;
	static const int DEFAULT_LENGTH;
	static const int DEFAULT_VALUE;
	CTABLE();
	CTABLE(std::string name, int table_length);
	CTABLE(const CTABLE &other);
	~CTABLE();
	void set_Name(std::string new_Name);
	std::string get_Name();
	bool set_Table_Length(int new_Table_Length);
	int get_Table_Length();
	bool index_Check(int index);
	bool set_Value(int new_Value, int index);
	bool get_Value(int index, int * value);
	std::string get_Info();
	void push(int new_value);

private:
	std::string name;
	int* table;
	int table_length;

};

