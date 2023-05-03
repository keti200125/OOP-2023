#ifndef POT_ROW_H
#define POT_ROW_H

#include "Plants.h"


class PotRow
{
private:
	Plants* mSunny;
	Plants* mNeutral;
	Plants* mShady;
	size_t mSunnySize;
	size_t mNeutralSize;
	size_t mShadySize;

	size_t mCountSunny;
	size_t mCountNeutral;
	size_t mCountShady;

	void copyFrom(const PotRow& other);
	void free();
	void move(PotRow&& other);
public:

	PotRow();
	PotRow(size_t, size_t, size_t);
	PotRow(const PotRow& other);
	PotRow& operator=(const PotRow& other);
	~PotRow();

	const Plants* getSunny() const;
	const Plants* getNeutral() const;
	const Plants* getShady() const;

	size_t getSunnySize() const;
	size_t getNeutralSize() const;
	size_t getShadySize() const;

	size_t getCountSunny() const;
	size_t getCountNeutral() const;
	size_t getCountShady() const;

	void setCountSunny();
	void setCountNeutral();
	void setCountShady();

	void addElement(Location loc,size_t wateringDays, const char* species);
	void addElementSunny(Location loc, size_t wateringDays, const char* species);
	void addElementNeutral(Location loc, size_t wateringDays, const char* species);
	void addElementShady(Location loc, size_t wateringDays, const char* species);
	
	Plants removeElement(Location row, size_t col);

	void print() const;
	void printStatistic() const;


	PotRow(PotRow&&) noexcept;
	PotRow& operator=(PotRow&&) noexcept;

	//for greenhousebook
	friend std::istream& operator>>(std::istream& in, PotRow& pot);
	friend std::ostream& operator<<(std::ostream& out, const PotRow& pot);
};







#endif
