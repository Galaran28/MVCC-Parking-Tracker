#include<iostream>
#include<time.h>
#include<ctime>
using namespace std;

class randHead
{
public:
	randHead();
	void getCars();
	int getShermanACars();
	int getShermanBCars();
	int getTildenACars();
	int getTildenBCars();
	int getArmoryCars();
private:
	int random, randCarsPerHour, hour;
	int shermanA, shermanB, tildenA, armory, tildenB;
};
