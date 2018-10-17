#include "stdafx.h"
#include "CTABLE.h"
#include <iostream>
#include <algorithm>
#include <sstream>
const std::string CTABLE::DEFAULT_NAME = "DEFAULT";
const int CTABLE::DEFAULT_LENGTH = 4;
const int CTABLE::DEFAULT_VALUE = 1;
CTABLE::CTABLE()
{
	name = DEFAULT_NAME;
	table_length = DEFAULT_LENGTH;
	table = new int[table_length];
	//std::fill_n(table, table_length, DEFAULT_VALUE);
	std::cout << "bezp:" << name << std::endl;
}

CTABLE::CTABLE(std::string dir_name, int dir_table_length)
{
	name = dir_name;
	table_length = dir_table_length;
	table = new int[table_length];
	//std::fill_n(table, table_length, DEFAULT_VALUE);
	std::cout << "parametr:" << name << std::endl;
}

CTABLE::CTABLE(CTABLE &other)
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

void CTABLE::set_Table_Length(int new_Table_Length)
{
	int* new_Table = new int[new_Table_Length];
	memcpy(new_Table, table, std::min(new_Table_Length, table_length) * sizeof(int));
	delete[] table;
	table = new_Table;
	table_length = new_Table_Length;
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
	if (index_Check)
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
	for (int i = 0; i <= table_length; i++)
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