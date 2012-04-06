#include<iostream>
#include<time.h>
#include<ctime>
using namespace std;

class randHead
{
public:
	randHead();
	//void generateCars(int);
	int getShermanACars();
	int getShermanBCars();
	int getTildenACars();
	int getTildenBCars();
	int getArmoryCars();
private:
	int random, randCarsPerHour;
	int shermanA, shermanB, tildenA, armory, tildenB;
};
