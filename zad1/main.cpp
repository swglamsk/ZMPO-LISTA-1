#include <iostream>
#include "CTable.h"
#include <vector>
#include <string>

int main()
{
	int number_of_tables;
	int what_to_do;
	int index_of;
	int type_table_length;
	int type_index_of_value;
	int type_value;
	std::string type_name;

	std::cout << "Podaj liczbe tablic ktore chcesz utowrzyc" << std::endl;
	std::cin >> number_of_tables;
	std::vector<CTABLE> array_of_tables(number_of_tables);

	while (true)
	{
		std::cout << "Wybierz co chcesz zrobic:" << std::endl;
		std::cout << "0. Stworz nowy obiekt CTable" << std::endl;
		std::cout << "1. Okresl dlugosc tablicy dla dowolnego obiektu CTable" << std::endl;
		std::cout << "2. Skasuj dowolny obiekt CTable" << std::endl;
		std::cout << "3. Skasuj wszystkie obiekty CTable" << std::endl;
		std::cout << "4. Nadaj now¹ nazwe dowolnemu obiektowi CTable" << std::endl;
		std::cout << "5. Sklonuj dowolny obiekt i dodaj do listy obiektów CTable" << std::endl;
		std::cout << "6. Wypisz status dowolnego obiektu CTable" << std::endl;
		std::cout << "7. Wpisz wartosc dla dowolnej komórki wybranego obiektu CTable" << std::endl;
		std::cout << "8. Zakoncz dzialanie programu" << std::endl;
		std::cout << "9. Push" << std::endl;
		std::cin >> what_to_do;
		switch (what_to_do)
		{
		case 0:
		{	
		std::cout << "Podaj nazwe obiektu:" << std::endl;
		std::cin >> type_name;
		std::cout << "Podaj rozmiar tablicy obiektu:" << std::endl;
		std::cin >> type_table_length;
		CTABLE tmp(type_name, type_table_length);
		array_of_tables.push_back(tmp);
		number_of_tables++;
		std::cout << "Dodano nowy obiekt." << std::endl;
		break;
		}

		case 1:
			std::cout << "Podaj indeks obiektu ktory chcesz zmienic" << std::endl;
			std::cin >> index_of;
			if (index_of > number_of_tables - 1 || index_of < 0)
				std::cout << "Indeks poza zasiêgiem" << std::endl;
			else
			{
				std::cout << "Podaj dlugosc tablicy" << std::endl;
				std::cin >> type_table_length;
				if (type_table_length < 0)
					std::cout << "Dlugosc nie moze byc mniejsza od 0" << std::endl;
				else
					array_of_tables.at(index_of).set_Table_Length(type_table_length);
			}
			break;
		case 2:
			std::cout << "Podaj indeks obiektu który chcesz usunac" << std::endl;
			std::cin >> index_of;
			if (index_of > number_of_tables - 1 || index_of < 0)
				std::cout << "Indeks poza zasiêgiem" << std::endl;
			else
				array_of_tables.erase(array_of_tables.begin() + index_of);
			break;

		case 3:
			array_of_tables.clear();
			std::cout << "Usunieto wszystkie obiekty CTable" << std::endl;
			break;

		case 4:
			std::cout << "Podaj indeks obiektu któremu chcesz nadac nowa nazwe" << std::endl;
			std::cin >> index_of;
			if (index_of > number_of_tables - 1 || index_of < 0)
				std::cout << "Indeks poza zasiêgiem" << std::endl;
			else
			{
				std::cout << "Podaj now¹ nazwe" << std::endl;
				std::cin >> type_name;
				array_of_tables.at(index_of).set_Name(type_name);
				break;
			}
		case 5: {
			std::cout << "Podaj indkes obiektu ktory chcesz sklonowac:" << std::endl;
			std::cin >> index_of;
			if (index_of > number_of_tables - 1 || index_of < 0 )
				std::cout << "Indeks poza zasiegiem" << std::endl;
			else
			{
				CTABLE tmp(array_of_tables.at(index_of));
				array_of_tables.push_back(tmp);
				number_of_tables++;
				break;
			}
		}
		case 6:
			std::cout << "Podaj indeks obiektu ktorego chcesz wypisac dane" << std::endl;
			std::cin >> index_of;
			if (index_of > number_of_tables - 1 || index_of < 0)
				std::cout << "Indeks poza zasiegiem" << std::endl;
			else
			std::cout << array_of_tables.at(index_of).get_Info() << std::endl;
			break;
		case 7:
			std::cout << "Podaj indeks obiektu ktoremu chcesz zmodyfikowac wartosc:" << std::endl;
			std::cin >> index_of;
			if (index_of > number_of_tables - 1 || index_of < 0)
				std::cout << "Indeks poza zasiêgiem" << std::endl;
			else
			std::cout << "Podaj inkes komorki ktorej chcesz zmodyfikowac dane:" << std::endl;
			std::cin >> type_index_of_value;
			if (index_of > array_of_tables.at(type_index_of_value).get_Table_Length() || index_of < 0)
				std::cout << "Indeks poza zasiêgiem" << std::endl;
			else
			std::cout << "Podaj nowa wartosc:" << std::endl;
			std::cin >> type_value;
			array_of_tables.at(index_of).set_Value(type_value, type_index_of_value);
			break;

		case 8:
			array_of_tables.clear();
			std::vector<CTABLE>().swap(array_of_tables);
			return 0;
			break;
		
		case 9:
			std::cout << "Podaj nowa wartosc" << std::endl;
			std::cin >> type_value;
			std::cout << "Podaj idndeks w ktorym chcesz zmienic tablice" << std::endl;
			std::cin >> index_of;
			if (index_of > number_of_tables - 1 || index_of < 0)
				std::cout << "Indeks poza zasiegiem" << std::endl;
			else
				array_of_tables.at(index_of).push(type_value);
			break;
							
		}
	}
}