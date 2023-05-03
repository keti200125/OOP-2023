#include "Greenhouse.h"
#include "PotRow.h"
#include<iostream>


Greenhouse::Greenhouse(size_t sunnySize, size_t neutralSize, size_t shadySize, const char* bookName) :mSpeciesThatCanGrowHere(bookName), mPotRows(sunnySize, neutralSize, shadySize)
{
	mSpeciesThatCanGrowHere.readFromFile();
}

void Greenhouse::print() const
{
	mSpeciesThatCanGrowHere.print();
	std::cout << std::endl;
	mPotRows.print();

}

Plants Greenhouse::removePlant(Location row, size_t col)
{
	Plants p2;
	p2=mPotRows.removeElement(row,col);
	return p2;
}

void Greenhouse::statistics() const
{
	mPotRows.printStatistic();
}

void Greenhouse::addPlant(Plants& plant)
{
	size_t size = mSpeciesThatCanGrowHere.getSpeciesCount();
	bool help=0;
	Species newS;
	for (size_t i=0; i < size; i++)
	{
		Species species = mSpeciesThatCanGrowHere.getSpeciesOnIndex(i);
		if (strcmp(plant.getSpecies(), species.getName()) == 0)
		{
			help = 1;
			newS = species;
		}
	}

	if (help == 0)
	{
		throw std::exception("There is no species with that name in the plants book");
	}

	Location locWeWant = newS.getLocation();
	size_t wateringDaysWeWant = newS.getWateringDays();

	if (mPotRows.getCountNeutral() == mPotRows.getNeutralSize() && mPotRows.getCountShady() == mPotRows.getShadySize() && mPotRows.getCountSunny() == mPotRows.getSunnySize())
	{
		throw std::exception("There is no space in the po rows");
	}
	mPotRows.addElement(locWeWant, wateringDaysWeWant, plant.getSpecies());

}

