#include "Species.h"
#include<iostream>
#include<cstring>
#pragma warning(disable: 4996)

#include "Species.h"



void Species::copyFrom(const Species& other)
{
	setName(other.mName);
	setLocation(other.mLocation);
	setWateringDays(other.mWateringDays);
}

void Species::free()
{
	delete[] mName;
}

void Species::move(Species&& other)
{
	mWateringDays = other.mWateringDays;
	mLocation = other.mLocation;
	mName = other.mName;
	other.mName = nullptr;
}


//BIG 4
Species::Species()
{
	mName = nullptr;
	mLocation = Location::neutral;
	mWateringDays = 3;
}

Species::Species(const char* name, Location location, size_t wateringDays)
{
	setName(name);
	setLocation(location);
	setWateringDays(wateringDays);
}
Species::Species(const char* name, Location location)
{
	setName(name);
	setLocation(location);
	mWateringDays = 3;
}
Species::Species(const char* name, size_t wateringDays)
{
	setName(name);
	setWateringDays(wateringDays);
	mLocation = Location::neutral;
}


Species::Species(const char* name)
{
	setName(mName);
	mLocation = Location::neutral;
	mWateringDays = 3;
}

Species::Species(const Species& other) 
{
	setName(other.mName);
	setLocation(other.mLocation);
	setWateringDays(other.mWateringDays);
}

Species& Species::operator=(const Species& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Species::~Species()
{
	free();
}

//Move
Species::Species(Species&& other) noexcept
{
	move(std::move(other));
}

Species& Species::operator=(Species&& other) noexcept
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}

	return *this;
}


//set
void Species::setName(const char* name)
{
	if (name && mName != name)  
	{
		if (mName != nullptr)
			delete[] mName;
		mName = new char[strlen(name) + 1];
		strcpy(mName, name);
	}
}

void Species::setLocation(Location location)
{
	mLocation = location;
}

void Species::setWateringDays(size_t wateringDays)
{
	mWateringDays = wateringDays;
}

//get
const char* Species::getName() const
{
	return mName;
}

Location Species::getLocation() const
{
	return mLocation;
}

size_t Species::getWateringDays() const 
{
	return mWateringDays;
}


void Species::print() const
{
	std::cout << "Type: " << mName << std::endl;
	std::cout << "Location: ";
	switch (mLocation)
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
	std::cout << std::endl;
	std::cout << "Watering days: " << mWateringDays << std::endl;
}


std::ostream& operator<<(std::ostream& out, const Species& species)
{
	size_t size = strlen(species.mName);
	out <<size<< ' ';
	for (int i = 0; i<size; i++)
	{
		out << species.mName[i];
	}
	out << ' ';
	switch (species.mLocation)
	{
	case Location::sunny:
		out << "sunny";
		break;
	case Location::shady:
		out << "shady";
		break;
	case Location::neutral:
		out << "neutral";
	default:
		break;
	}

	out << ' ';

	out << species.mWateringDays;
	

	return out;
}

std::istream& operator>>(std::istream& in, Species& species)
{
	size_t size;
	in >> size;
	species.mName = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		in >> species.mName[i];
	}

	species.mName[size] = '\0';

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
		species.mLocation = Location::sunny;
	}
	if (time[1] == 'e')
	{
		species.mLocation = Location::neutral;
	}
	if (time[1] == 'h')
	{
		species.mLocation = Location::shady;
	}

	in >> species.mWateringDays;
	
	return in;
	
}

