#include "PotRow.h"
#include<iostream>



void PotRow::copyFrom(const PotRow& other)
{
	mSunnySize = other.mSunnySize;
	mNeutralSize = other.mNeutralSize;
	mShadySize = other.mShadySize;

	mSunny = new Plants[mSunnySize];
	for (size_t i = 0; i < mSunnySize; i++)
	{
		mSunny[i] = other.mSunny[i];
	}
	mNeutral = new Plants[mNeutralSize];
	for (size_t i = 0; i < mNeutralSize; i++)
	{
		mNeutral[i] = other.mNeutral[i];
	}
	mShady = new Plants[mShadySize];
	for (size_t i = 0; i < mShadySize; i++)
	{
		mShady[i] = other.mShady[i];
	}

	size_t mCountSunny=other.mCountSunny;
	size_t mCountNeutral=other.mCountNeutral;
	size_t mCountShady=other.mCountShady;
}
void PotRow::free()
{
	delete[] mSunny;
	delete[] mShady;
	delete[] mNeutral;
}
void PotRow::move(PotRow&& other)
{
	mCountSunny = other.mCountSunny;
	mCountNeutral = other.mCountNeutral;
	mCountShady = other.mCountShady;
	mSunny = other.mSunny;
	mNeutral = other.mNeutral;
	mShady = other.mShady;
	mSunnySize = other.mSunnySize;
	mNeutralSize = other.mNeutralSize;
	mShadySize = other.mShadySize;
	other.mSunny = nullptr;
	other.mNeutral = nullptr;
	other.mShady = nullptr;
}

PotRow::PotRow()
{
	mSunny = nullptr;
	mNeutral = nullptr;
	mShady = nullptr;
	mSunnySize = 0;
	mNeutralSize=0;
	mShadySize=0;
	mCountSunny =0;
	mCountNeutral = 0;
	mCountShady = 0;
}
PotRow::PotRow(size_t sunnySize, size_t neutralSize, size_t shadySize)
{
	mSunnySize = sunnySize;
	mNeutralSize = neutralSize;
	mShadySize = shadySize;

	mSunny = new Plants[mSunnySize];
	mNeutral = new Plants[mNeutralSize];
	mShady = new Plants[mShadySize];

	for (size_t i = 0; i < mSunnySize; i++)
	{
		mSunny[i] = Plants("none");
	}
	for (size_t i = 0; i < mNeutralSize; i++)
	{
		mNeutral[i] = Plants("none");
	}
	for (size_t i = 0; i < mShadySize; i++)
	{
		mShady[i] = Plants("none");
	}

	mCountSunny = 0;
	mCountNeutral = 0;
	mCountShady = 0;
}
PotRow::PotRow(const PotRow& other)
{
	copyFrom(other);
}
PotRow& PotRow::operator=(const PotRow& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
PotRow::~PotRow()
{
	free();
}

PotRow::PotRow(PotRow&& other) noexcept
{
	move(std::move(other));
}
PotRow& PotRow::operator=(PotRow&& other) noexcept
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}
	return *this;
}

const Plants* PotRow::getSunny() const
{
	return mSunny;
}
const Plants* PotRow::getNeutral() const
{
	return mNeutral;
}
const Plants* PotRow::getShady() const
{
	return mShady;
}

size_t PotRow::getSunnySize() const
{
	return mSunnySize;
}
size_t PotRow::getNeutralSize() const
{
	return mNeutralSize;
}
size_t PotRow::getShadySize() const
{
	return mShadySize;
}

size_t PotRow::getCountSunny() const
{
	return mCountSunny;
}
size_t PotRow::getCountNeutral() const
{
	return mCountNeutral;
}
size_t PotRow::getCountShady() const
{
	return mCountShady;
}

void PotRow::setCountSunny()
{
	mCountSunny++;
}
void PotRow::setCountNeutral()
{
	mCountNeutral++;
}
void PotRow::setCountShady()
{
	mCountShady++;
}

void PotRow::addElementShady(Location loc, size_t wateringDays, const char* species)
{
	Plants plant(species);
	size_t water = 0;
	if (mCountShady < mShadySize)
	{
		plant.setLocation(Location::shady);
		plant.setWateringDays(wateringDays);
		for (size_t i = 0; i < mShadySize; i++)
		{
			if (strcmp(mShady[i].getSpecies(), "none") == 0)
			{
				mShady[i] = plant;
				mCountShady++;
				break;
			}
		}
	}
	else
	{
		if (mCountNeutral < mNeutralSize)
		{
			plant.setLocation(Location::neutral);
			water = wateringDays;
			if (wateringDays > 1)
			{
				water = wateringDays - 1;
			}
			plant.setWateringDays(water);
			for (size_t i = 0; i < mNeutralSize; i++)
			{
				if (strcmp(mNeutral[i].getSpecies(), "none") == 0)
				{
					mNeutral[i] = plant;
					mCountNeutral++;
					break;
				}
			}
			
		}
		else
		{
			plant.setLocation(Location::sunny);
			water = wateringDays;
			if (wateringDays > 1)
			{
				water = wateringDays - 1;
			}
			if (wateringDays > 2)
			{
				water = wateringDays - 2;
			}
			plant.setWateringDays(water);
			for (size_t i = 0; i < mSunnySize; i++)
			{
				if (strcmp(mSunny[i].getSpecies(), "none") == 0)
				{
					mSunny[i] = plant;
					mCountSunny++;
					break;
				}
			}
		}
	}
}
void PotRow::addElementNeutral(Location loc, size_t wateringDays, const char* species)
{
	Plants plant(species);
	size_t water = 0;
	if (mCountNeutral < mNeutralSize)
	{
		plant.setLocation(Location::neutral);
		plant.setWateringDays(wateringDays);
		for (size_t i = 0; i < mNeutralSize; i++)
		{
			if (strcmp(mNeutral[i].getSpecies(), "none") == 0)
			{
				mNeutral[i] = plant;
				mCountNeutral++;
				break;
			}
		}
	}
	else
	{
		if (mCountShady < mShadySize)
		{
			plant.setLocation(Location::shady);
			water = wateringDays + 1;
			plant.setWateringDays(water);
			for (size_t i = 0; i < mShadySize; i++)
			{
				if (strcmp(mShady[i].getSpecies(), "none") == 0)
				{
					mShady[i] = plant;
					mCountShady++;
					break;
				}
			}
		}
		else
		{
			plant.setLocation(Location::sunny);
			water = wateringDays;
			if (wateringDays > 1)
			{
				water = wateringDays - 1;
			}

			plant.setWateringDays(water);
			for (size_t i = 0; i < mSunnySize; i++)
			{
				if (strcmp(mSunny[i].getSpecies(), "none") == 0)
				{
					mSunny[i] = plant;
					mCountSunny++;
					break;
				}
			}
		}
	}
}
void PotRow::addElementSunny(Location loc, size_t wateringDays, const char* species)
{
	Plants plant(species);
	size_t water = 0;

	if (mCountSunny < mSunnySize)
	{

		plant.setLocation(Location::sunny);
		plant.setWateringDays(wateringDays);
		for (size_t i = 0; i < mSunnySize; i++)
		{
			if (strcmp(mSunny[i].getSpecies(), "none") == 0)
			{
				mSunny[i] = plant;
				mCountSunny++;
				break;
			}
		}
	}
	else
	{
		if (mCountNeutral < mNeutralSize)
		{
			plant.setLocation(Location::neutral);
			water = wateringDays + 1;
			plant.setWateringDays(water);
			for (size_t i = 0; i < mNeutralSize; i++)
			{
				if (strcmp(mNeutral[i].getSpecies(), "none") == 0)
				{
					mNeutral[i] = plant;
					mCountNeutral++;
					break;
				}
			}
		}
		else
		{
			plant.setLocation(Location::shady);
			water = wateringDays + 2;
			plant.setWateringDays(water);
			for (size_t i = 0; i < mShadySize; i++)
			{
				if (strcmp(mShady[i].getSpecies(), "none") == 0)
				{
					mShady[i] = plant;
					mCountShady++;
					break;
				}
			}
			
		}
	}
}

void PotRow::addElement(Location loc,size_t wateringDays, const char* species)
{
	if (loc == Location::sunny)
	{
		addElementSunny(loc, wateringDays, species);
	}
	if (loc == Location::neutral)
	{
		addElementNeutral(loc, wateringDays, species);
	}
	if (loc == Location::shady)
	{
		addElementShady(loc, wateringDays, species);
	}
}
Plants PotRow::removeElement(Location row, size_t col)
{
	Plants p;
	if (row == Location::sunny)
	{
		p = mSunny[col];
		mSunny[col] = Plants("none");

	}
	if (row == Location::neutral)
	{
		p = mNeutral[col];
		mNeutral[col] = Plants("none");
	}
	if (row == Location::shady)
	{
		p = mShady[col];
		mShady[col] = Plants("none");
	}

	return p;
}
void PotRow::printStatistic() const
{
	size_t count=0;
	for (size_t i = 0; i < mSunnySize; i++)
	{
		if (strcmp(mSunny[i].getSpecies(), "none") != 0)
		{
			count++;
		}
	}
	std::cout << "Location sunny: " << count << std::endl;
	count = 0;
	for (size_t i = 0; i < mNeutralSize; i++)
	{
		if (strcmp(mNeutral[i].getSpecies(), "none") != 0)
		{
			count++;
		}
	}
	std::cout << "Location neutral: " << count << std::endl;
	count = 0;
	for (size_t i = 0; i < mShadySize; i++)
	{
		if (strcmp(mShady[i].getSpecies(), "none") != 0)
		{
			count++;
		}
	}
	std::cout << "Location shady: " << count << std::endl;

}

void PotRow::print() const
{
	std::cout << "   Sunny: " << std::endl;
	for (size_t i=0; i < mSunnySize; i++)
	{
		if (strcmp(mSunny[i].getSpecies(), "none") != 0)
		{
			mSunny[i].print();
		}
	}
	std::cout << "   Neutral: " << std::endl;
	for (size_t i=0; i < mNeutralSize; i++)
	{
		if (strcmp(mNeutral[i].getSpecies(), "none") != 0)
		{
			mNeutral[i].print();
		}
	}
	std::cout << "   Shady: " << std::endl;
	for (size_t i=0; i < mShadySize; i++)
	{
		if (strcmp(mShady[i].getSpecies(), "none") != 0)
		{
			mShady[i].print();
		}
	}
}

std::istream& operator>>(std::istream& in, PotRow& pot)
{
	in >> pot.mSunnySize;
	in >> pot.mNeutralSize;
	in>> pot.mShadySize;

	in >> pot.mCountSunny;
	in >> pot.mCountNeutral;
	in >> pot.mCountShady;

	for (size_t i = 0; i < pot.mSunnySize; i++)
	{
		in >> pot.mSunny[i];
	}

	for (size_t i = 0; i < pot.mNeutralSize; i++)
	{
		in >> pot.mNeutral[i];
	}
	for (size_t i = 0; i < pot.mShadySize; i++)
	{
		in >> pot.mShady[i];
	}

	return in;
}
std::ostream& operator<<(std::ostream& out, const PotRow& pot)
{
	out << pot.mSunnySize << ' ';
	out << pot.mNeutralSize << ' ';
	out << pot.mShadySize << ' ';

	out << pot.mCountSunny << ' ';
	out << pot.mCountNeutral << ' ';
	out << pot.mCountShady << ' ';

	for (size_t i = 0; i < pot.mSunnySize; i++)
	{
		out << pot.mSunny[i] << ' ';
	}

	for (size_t i = 0; i < pot.mNeutralSize; i++)
	{
		out << pot.mNeutral[i] << ' ';
	}
	for (size_t i = 0; i < pot.mShadySize; i++)
	{
		out << pot.mShady[i] << ' ';
	}


	return out;

}


