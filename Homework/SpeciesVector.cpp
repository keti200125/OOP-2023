#include "SpeciesVector.h"
#include<iostream>
#include <climits>
#include<cstring>
#include<stdexcept>




void SpeciesVector::free()
{
	delete[] mAllSpecies;
}


void SpeciesVector::copyFrom(const SpeciesVector& other)
{
	mCount = other.mCount;
	//mAllSpecies = new Species[mCount];
	mCapacity = other.mCapacity;
	if (other.mAllSpecies && mCapacity>=mCount)
	{
		mAllSpecies = new Species[mCapacity];
		//allocate(other.mCapacity);
		//mCount = other.mCount;
		for (size_t i = 0; i < mCount; i++)
		{
			mAllSpecies[i] = other.mAllSpecies[i];
		}

	}


}

void SpeciesVector::move(SpeciesVector&& other)
{
	mCount = other.mCount;
	mCapacity = other.mCapacity;
	mAllSpecies = other.mAllSpecies;
	other.mAllSpecies = nullptr;

}


void SpeciesVector::allocate(const size_t capacity)
{
	//mCount = 0;
	mCapacity = capacity;
	mAllSpecies = new Species[mCapacity];
}

void SpeciesVector::changeCapacity()
{
	if (mCount == mCapacity)
	{
		mCapacity *= 2;
		size_t count = mCount;
		Species* oldSpecies = new Species[mCapacity];
		for (size_t i = 0; i < mCount; i++)
		{
			oldSpecies[i] = mAllSpecies[i];
		}

		delete[] mAllSpecies;
		mAllSpecies = oldSpecies;

		mCount = count;
	}
}


SpeciesVector::SpeciesVector()
{
	//allocate(5);
	mCapacity = 3;
	mAllSpecies = nullptr;
	mCount = 0;
}



SpeciesVector::SpeciesVector(const SpeciesVector& other)
{
	copyFrom(other);
}
SpeciesVector& SpeciesVector::operator=(const SpeciesVector& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
SpeciesVector::~SpeciesVector()
{
	free();
}

SpeciesVector::SpeciesVector(SpeciesVector&& other) noexcept
{
	move(std::move(other));
}
SpeciesVector& SpeciesVector::operator=(SpeciesVector&& other) noexcept
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}

	return *this;
}

void SpeciesVector::print() const
{
	std::cout << "Print: " << std::endl;
	for (size_t i = 0; i < mCount; i++)
	{
		mAllSpecies[i].print();
		std::cout << std::endl;
	}
}


void SpeciesVector::addSpeciesInCollection(const Species& species) 
{
	mCount += 1;
	if (mCount == 1)
	{
		Species* newSpecies = new Species[mCapacity];
		newSpecies[mCount - 1] = species;
		free();
		mAllSpecies = newSpecies;
		mCount = 1;
	}
	else
	{
		size_t y = -1;
		for (size_t i = 0; i < mCount-1; i++)
		{
			if (strcmp(species.getName(), mAllSpecies[i].getName()) == 0)
			{
				throw std::exception("There is a species with that name in the plants book");
			}
			if ((strcmp(species.getName(), mAllSpecies[i].getName())  <0) && y == -1)
			{
				y = i;
			}
		}

		if (mCapacity == mCount)
		{
			changeCapacity();
		}
		mAllSpecies[mCount - 1] = species;

		if (y != -1)
		{
			Species* copySpecies = new Species[mCapacity];
			for (size_t i = 0; i <y; i++) {
				copySpecies[i] = mAllSpecies[i];
			}
			copySpecies[y] = species;

			for (size_t i = y; i < mCount - 1; i++)
			{
				copySpecies[i + 1] = mAllSpecies[i];
			}

			delete[] mAllSpecies;
			mAllSpecies = copySpecies;

		}
	}
}

std::istream& operator>>(std::istream& in, SpeciesVector& collection)
{
	size_t currPos = in.tellg();
	in.seekg(0, std::ios::beg);
	size_t count = 0;
	while (true)
	{
		char curr = in.get();
		if (in.eof())
			break;
		if (curr == '\n')
			count++;
	}
	in.clear();
	in.seekg(currPos);


	Species species;
	for (int i = 0; i < count; i++)
	{
		in >> species;
		collection.addSpeciesInCollection(species);
		in.get();
	}

	return in;
}
std::ostream& operator<<(std::ostream& out, const SpeciesVector& collection)
{
	for (int i = 0; i <collection.mCount; i++)
	{
		out << collection.mAllSpecies[i];
		out << '\n';
	}

	return out;
}

Species SpeciesVector::getSpeciesOnIndex(size_t i) const
{
	return mAllSpecies[i];
}

size_t SpeciesVector::getSpeciesCount() const
{
	return mCount;
}