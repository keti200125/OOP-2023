

#include "Plants.h"
#pragma warning(disable: 4996)
#include<iostream>


void Plants::copy(const Plants& other)
{
	if (other.mSpecies)
	{
		this->mSpecies = new char[strlen(other.mSpecies) + 1];
		strcpy(mSpecies, other.mSpecies);
	}

	mLivingLocation = other.mLivingLocation;
	mWateringDaysPlace = other.mWateringDaysPlace;
}

void Plants::free()
{
	delete[] mSpecies;
}

Plants::Plants(const char* species)
{ 
	setSpecies(species);
	mLivingLocation = Location::none;
	mWateringDaysPlace = 0;
}


Plants::Plants()
{
	mSpecies = nullptr;
	mLivingLocation = Location::none;
	mWateringDaysPlace = 0;
}

Plants::Plants(const Plants& other)
{
	copy(other);
}
Plants& Plants::operator=(const Plants& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}
Plants::~Plants()
{
	free();
}

const char* Plants::getSpecies() const
{
	return mSpecies;
}
Location Plants::getLivingLocation() const
{
	return mLivingLocation;
}
size_t Plants::getWateringDays() const
{
	return mWateringDaysPlace;
}


void Plants::setSpecies(const char* species)
{
	if (species)
	{
		this->mSpecies = new char[strlen(species) + 1];
		strcpy(mSpecies, species);
	}
}
void Plants::setLocation(Location livingLocation)
{
	mLivingLocation = livingLocation;
}
void Plants::setWateringDays(size_t wateringDaysPlace)
{
	mWateringDaysPlace = wateringDaysPlace;
}

void Plants::print() const
{
	std::cout << "Type: ";
	size_t len = strlen(mSpecies);
	for (size_t i = 0; i < len; i++)
	{
		std::cout << mSpecies[i];
	}
	std::cout << " ";
	std::cout << "Location: ";
	switch (mLivingLocation)
	{
	case Location::sunny:
		std::cout << "sunny";
		break;
	case Location::shady:
		std::cout << "shady";
		break;
	case Location::neutral:
		std::cout << "neutral";
	default:
		break;
	}
	std::cout << " ";
	std::cout << "Watering days: " <<mWateringDaysPlace<< std::endl;

}

std::ostream& operator<<(std::ostream& out, const Plants& plant)
{
	size_t size = strlen(plant.mSpecies);
	out << size << ' ';
	for (int i = 0; i < size; i++)
	{
		out << plant.mSpecies[i];
	}
	out << ' ';
	switch (plant.mLivingLocation)
	{
	case Location::sunny:
		out << "sunny";
		break;
	case Location::shady:
		out << "shady";
		break;
	case Location::neutral:
		out << "neutral";
	case Location::none:
		out << "none";
	default:
		break;
	}

	out << ' ';

	out << plant.mWateringDaysPlace;


	return out;
}

std::istream& operator>>(std::istream& in, Plants&  plant)
{
	size_t size;
	in >> size;
	plant.mSpecies = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		in >> plant.mSpecies[i];
	}

	plant.mSpecies[size] = '\0';

	char time[10] = " ";
	size_t index = 0;
	size_t end = 10;
	while (index < end)
	{
		in >> time[index];
		if (time[index] == 'y')
		{
			end = index;
		}
		if (time[index] == 'l')
		{
			end = index;
		}
		index++;
	}

	if (time[1] == 'u')
	{
		plant.mLivingLocation = Location::sunny;
	}
	if (time[1] == 'e')
	{
		plant.mLivingLocation = Location::neutral;
	}
	if (time[1] == 'h')
	{
		plant.mLivingLocation = Location::shady;
	}
	if (time[1] == 'o')
	{
		plant.mLivingLocation = Location::none;
	}

	in >> plant.mWateringDaysPlace;

	return in;

}