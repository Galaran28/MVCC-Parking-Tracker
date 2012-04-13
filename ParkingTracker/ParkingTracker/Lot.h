#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Lot
{
public:
	Lot(int);
	int getCurrentSize();
	int getMaxSize();
	double getPercentage();
	void Add();
	int getRemainingSpots();
	void Subtract();
	bool IsFull();
	bool IsEmpty();
	bool OverFull();
	void PercentageFull();
	void SizeChange(int);
	void ResetToDefaultSize();
	void ChangeTotals(string, int, string);

private:
	int currentSize, maxSize, defaultSize;
	double percentage;
	string lotName;
};

//this is a test 2
