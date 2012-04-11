#include<iostream>
#include<time.h>
#include<ctime>
using namespace std;

class randHead
{
public:
	randHead();
	int generateCars(int);
	int generateLeaving(int);
	int leavingLot();
/*	int getShermanACars();
	int getShermanBCars();
	int getTildenACars();
	int getTildenBCars();
	int getArmoryCars();*/
	int distributeCars();

private:
	int random, randCarsPerHour;
	//int shermanA, shermanB, tildenA, armory, tildenB; 
	int lot;
};
