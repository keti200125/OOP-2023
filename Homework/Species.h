#ifndef SPECIES_H
#define SPECIES_H

#include<fstream>


enum class Location
{
	sunny,
	neutral,
	shady,
	none
};

class Species
{
private:
	char* mName;
	Location mLocation;
	size_t mWateringDays;

	void copyFrom(const Species&);
	void free();
	void move(Species&&);
public:
	//big 4
	Species();
	Species(const char*, Location, size_t);
	Species(const char*);
	Species(const char*, Location);
	Species(const char*, size_t);
	Species(const Species&);
	Species& operator=(const Species&);
	~Species();
	//Move
	Species(Species&&) noexcept;
	Species& operator=(Species&&) noexcept;

	//set functions
	void setName(const char*);
	void setLocation(Location);
	void setWateringDays(size_t);
	//get functions
	const char* getName() const;
	Location getLocation() const;
	size_t getWateringDays() const;

	friend std::istream& operator>>(std::istream& in, Species& species);
	friend std::ostream& operator<<(std::ostream& out, const Species& species);

	void print() const;

};



#endif
