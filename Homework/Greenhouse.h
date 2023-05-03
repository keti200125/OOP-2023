#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include "PlantsBook.h"
#include "PotRow.h"


class Greenhouse
{
private:
	PlantsBook mSpeciesThatCanGrowHere;
	PotRow mPotRows;
public:
	Greenhouse(size_t,size_t,size_t,const char* bookName);

	void addPlant(Plants& plant);
	Plants removePlant(Location row, size_t col);
	void print() const;
	void statistics() const;

};




#endif