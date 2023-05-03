#ifndef SPECIES_VECTOR_H
#define SPECIES_VECTOR_H


#include "Species.h"

class SpeciesVector
{
private:
	Species* mAllSpecies;
	size_t mCount;
	size_t mCapacity;

	void copyFrom(const SpeciesVector&);
	void move(SpeciesVector&&);
	void free();
	void allocate(const size_t capacity);
	void changeCapacity();



public:
	//big 4
	SpeciesVector();
	//PlantsBook(Species* allSpecies, size_t countSpecies, char* bookName);
	SpeciesVector(const SpeciesVector&);
	SpeciesVector& operator=(const SpeciesVector&);
	~SpeciesVector();

	//move
	SpeciesVector(SpeciesVector&&) noexcept;
	SpeciesVector& operator=(SpeciesVector&&) noexcept;

	//set
	//void setAllSpecies(Species* allSpecies);
	//void setNum(size_t num);
	//void setBookName(const char* bookName);

	//get 


	void addSpeciesInCollection(const Species&);
	void print() const;

	Species getSpeciesOnIndex(size_t i) const;
	size_t getSpeciesCount() const;
	friend std::istream& operator>>(std::istream& in, SpeciesVector& vectorCollection);
	friend std::ostream& operator<<(std::ostream& out, const SpeciesVector& vectorCollection);

};








#endif
