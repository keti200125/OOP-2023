
#include<iostream>
#include<fstream>
#include "Species.h"
#include "SpeciesVector.h"
#include "PlantsBook.h"
#include "Greenhouse.h"




int main()
{
	Species one("Orchids", Location::neutral, 4);
	Species two("Cactus", Location::sunny, 10);
	Species three("Rose", Location::neutral , 6);
	Species four("Tulip", Location::sunny, 5);
	Species five("Corn", Location::shady, 3);

	Plants num1("Orchids");
	Plants num2("Cactus");
	Plants num3("Rose");
	Plants num4("Tulip");
	Plants num5("Corn");

	PlantsBook book("Green.txt");
	book.addSpecies(one);
	book.addSpecies(two);
	book.addSpecies(three);
	book.addSpecies(four);
	book.addSpecies(five);

	PlantsBook book2("Green.txt");
	//book2.readFromFile();
	//book2.print();
	Greenhouse house(5, 5, 5, "Green.txt");

	house.addPlant(num1);
	house.addPlant(num2);
	house.addPlant(num3);
	house.addPlant(num4);
	house.addPlant(num5);

	house.print();
	std::cout << std::endl;

	Plants removed;

	removed=house.removePlant(Location::neutral, 0);
	house.print();
	std::cout << std::endl << "Removed: ";
	removed.print();
	std::cout << std::endl;

	house.statistics();
	

	// Plants num6("what");  This plant is not in the Plants book 
	// house.addPlant(num6);
}


/*
int main()
{

	//Species first("trees", Location::shady, 10);

	SpeciesVector collection;

	Species one("cflower", Location::sunny, 30);
	Species two("btree", Location::shady, 5);
	Species three("abush", Location::neutral, 16);
	Species four=three;
	
	PlantsBook book("STARO.txt");
	book.addSpecies(one);
	book.addSpecies(two);
	book.addSpecies(four);
	//book.addSpecies(three);

	PlantsBook book2("NOVO.txt");
	book2.readFromFile("STARO.txt");

	book2.print();


	//collection.addSpeciesInCollection(one);
	//collection.addSpeciesInCollection(two); 
	//collection.addSpeciesInCollection(four);
	//collection.addSpecies(cthree);
	
	//collection.print();
	/*
	std::ofstream file("NOVO.txt");

	if (!file.is_open())
	{
		return -1;
	}

	file << collection;

	//collection.print();

	file.close();

	SpeciesVector newVector;

	std::ifstream file2("HAIDE.txt");

	if (!file2.is_open())
	{
		return -1;
	}

	file2 >> newVector;


	file2.close();

	//collection.print();

	newVector.print();

	//book.print();

	//book.addSpecies(three);

	//book.print();
	
	*/
	
	//plantsBook.addSpecies(first);

	//plantsBook.print();




	/*

	std::ofstream file("Monday.txt");

	if (!file.is_open())
	if (!file.is_open())
	{
		return -1;
	}


	Species one("flowers", Location::sunny, 8);

	file << one;

	file.close();

	std::ifstream file2("Monday.txt");

	if (!file2.is_open())
	{
		return -1;
	}

	Species two;
	file2 >> two;
	two.print();
	file2.close();


	*/
