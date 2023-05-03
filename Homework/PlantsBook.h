


#ifndef PLANTS_BOOK_H
#define PLANTS_BOOK_H

#include "Species.h"
#include "SpeciesVector.h"

class PlantsBook
{
private:
	SpeciesVector mSpeciesCollection;
	char mBookName[129] = " ";

public:
	PlantsBook(const char* bookName);

	Species getSpeciesOnIndex(size_t i) const;
	size_t getSpeciesCount() const;
	void addSpecies(const Species& species);
	void print() const;
	void writeInFile();
	void readFromFile();




};








#endif 