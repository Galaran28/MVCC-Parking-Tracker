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
private:
	int random, randCarsPerHour, hour;
};
