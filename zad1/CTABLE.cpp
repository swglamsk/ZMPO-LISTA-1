#include "CTABLE.h"
#include <iostream>
#include <algorithm>
#include <sstream>
const std::string CTABLE::DEFAULT_NAME = "DEFAULT";
const int CTABLE::DEFAULT_LENGTH = 10;
const int CTABLE::DEFAULT_VALUE = 1;
CTABLE::CTABLE()
{
	name = DEFAULT_NAME;
	table_length = DEFAULT_LENGTH;
	table = new int[table_length];
	std::cout << "bezp:" << name << std::endl;
	for (int i = 0; i < table_length; i++)
		table[i] = DEFAULT_VALUE;
}

CTABLE::CTABLE(std::string dir_name, int dir_table_length)
{
	name = dir_name;
	table_length = dir_table_length;
	table = new int[table_length];
	std::cout << "parametr:" << name << std::endl;
	for (int i = 0; i < table_length; i++)
		table[i] = DEFAULT_VALUE;
}

CTABLE::CTABLE(const CTABLE  &other) 
{
	table_length = other.table_length;
	table = new int[table_length];
	memcpy(table, other.table, table_length * sizeof(int)); 
	name = other.name + "_copy";
	std::cout << "kopiuj:" << name << std::endl;
}

CTABLE::~CTABLE()
{
	delete[] table; 
	std::cout << "usuwam:" << name << std::endl;
}

void CTABLE::set_Name(std::string new_Name)
{
	name = new_Name;
}

std::string CTABLE::get_Name()
{
	return name;

}

bool CTABLE::set_Table_Length(int new_Table_Length)
{	
	if (new_Table_Length < 0)
		return false;
	else
	{
		int* new_Table = new int[new_Table_Length];
		memcpy(new_Table, table, std::min(new_Table_Length, table_length) * sizeof(int));
		if (new_Table_Length > table_length)
		{
			for (int i = table_length; i < new_Table_Length; i++) 
			{
				new_Table[i] = DEFAULT_VALUE;
			}
		}
		delete[] table;
		table = new_Table;
		table_length = new_Table_Length;
		return true;
	}
	
}

int CTABLE::get_Table_Length()
{
	return table_length;
}
bool CTABLE::index_Check(int index)
{
	if (index >= table_length || index < 0)
		return false;
	else
		return true;
}

bool CTABLE::set_Value(int new_Value, int index)
{
	if (index_Check(index))
	{
		table[index] = new_Value;
		return true;
	}
	else
		return false;
}

bool CTABLE::get_Value(int index, int * value)
{
	if (index_Check(index))
	{
		*value = *(table + index);
		return true;
	}
	else
		return false;
}

std::string CTABLE::get_Info()
{
	std::string values;
	for (int i = 0; i < table_length; i++)
	{
		std::string string_value;
		std::ostringstream convert;
		convert << table[i];
		string_value = convert.str();
		values += string_value + ",";
	}
	std::string string_table_length;
	std::ostringstream convert;
	convert << table_length;
	string_table_length = convert.str();
	return "(" + name + " " + "len:" + string_table_length + " " + "values:" + values + ")";
}

void CTABLE::push(int new_value) 
{
	int* new_table = new int[table_length + 1];
	new_table[0] = new_value;
	for (int i = 0; i <= table_length; i++)
		new_table[i + 1] = table[i];
	delete[] table;
	table = new_table;
	table_length = table_length + 1;
	
}