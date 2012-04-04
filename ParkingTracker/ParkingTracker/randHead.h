#include<iostream>
#include<time.h>
#include<ctime>
using namespace std;

class randHead
{
public:
	randHead();
	int getCars();
	void incrementHour();
	int getHours();
	void updateLot(int, Lot);
private:
	int random, randCarsPerHour, hour;
};
