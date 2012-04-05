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
	void Subtract();
	bool IsFull();
	void PercentageFull();
	void SizeChange(int);
	void ChangeTotals(string, int, string);
	void LogChange(string, int, string);
private:
	int currentSize, maxSize;
	double percentage;
};

//this is a test
