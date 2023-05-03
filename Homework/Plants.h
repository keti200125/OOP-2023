
#ifndef PLANTS_H
#define PLANTS_H

#include "Species.h"


class Plants
{
private:
	char* mSpecies;
	Location mLivingLocation;
	size_t mWateringDaysPlace;

	void copy(const Plants& other);
	void free();

public:
	Plants();
	Plants(const char*);
	Plants(const Plants& other);
	Plants& operator=(const Plants& other);
	~Plants();

	

	const char* getSpecies() const;
	Location getLivingLocation() const;
	size_t getWateringDays() const;

	void setSpecies(const char* species);
	void setLocation(Location livingLocation);
	void setWateringDays(size_t wateringDaysPlace);

	void print() const;

	//for Greenhousebook
	friend std::istream& operator>>(std::istream& in, Plants& plant);
	friend std::ostream& operator<<(std::ostream& out, const Plants& plant);
};








#endif