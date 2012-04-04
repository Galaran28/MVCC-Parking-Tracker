#include<iostream>
#include<time.h>
#include<ctime>
using namespace std;

class randHead
{
public:
	randHead();
<<<<<<< HEAD
	void getCars();
	int getShermanACars();
	int getShermanBCars();
	int getTildenACars();
	int getTildenBCars();
	int getArmoryCars();
=======
	int getCars();
	void incrementHour();
	int getHours();
	void updateLot(int, Lot);
>>>>>>> 1fd01bb094d51ecf019426e95a6dad244067e426
private:
	int random, randCarsPerHour, hour;
	int shermanA, shermanB, tildenA, armory, tildenB;
};
