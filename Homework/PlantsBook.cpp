
#include "PlantsBook.h"
#include<iostream>
#include<fstream>
#include<cstring>
#pragma warning(disable: 4996)



void PlantsBook::writeInFile()
{
	std::ofstream file(mBookName);

	if (!file.is_open())
	{
		throw std::invalid_argument("Could not open file!");
	}

	file << mSpeciesCollection;

	file.close();
}

void PlantsBook::readFromFile()
{
	std::ifstream file2(mBookName);

	if (!file2.is_open())
	{
		throw std::invalid_argument("Could not open file!");
	}

	file2.seekg(0, std::ios::beg);
	file2 >>mSpeciesCollection;


	file2.close();

}


PlantsBook::PlantsBook(const char* bookName)
{
	if (!bookName || strlen(bookName) > 128)
		return;
	strcpy(mBookName, bookName);
	
}



void PlantsBook::addSpecies(const Species& species) 
{
	mSpeciesCollection.addSpeciesInCollection(species);
	writeInFile();
}

Species PlantsBook::getSpeciesOnIndex(size_t i) const
{
	return mSpeciesCollection.getSpeciesOnIndex(i);
}

size_t PlantsBook::getSpeciesCount() const
{
	return mSpeciesCollection.getSpeciesCount();
}

void PlantsBook::print() const
{
	mSpeciesCollection.print();
}
