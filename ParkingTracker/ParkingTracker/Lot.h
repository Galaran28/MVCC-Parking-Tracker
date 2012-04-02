#include <iostream>
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
private:
	int currentSize, maxSize;
	double percentage;
};