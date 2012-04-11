#include "randHead.h"
#include "stdlib.h"
#include<time.h>
#include<ctime>
#include<iostream>
using namespace std;

randHead::randHead()
{
	srand(time(NULL));
	randCarsPerHour = rand() % 2490;
}

int randHead::generateCars(int hour)
{
	//set ceiling for number of cars based on time of day
	int randMax;
	if (hour <= 8)
	{
		randMax = hour * (rand() % 25) + 3;// not many cars
	}
	else if (hour == 9)
	{
		randMax = 1300; //spike of cars
	}
	else if (hour == 10 || hour == 11)
	{
		randMax = hour * (rand() % 300) + 1;//not many
	}
	else if (hour == 12)
	{
		randMax = 1000;//spike
	}
	else if (hour >= 13 && hour <= 17)
	{
		randMax = hour * (rand() % 200) + 1;//not many
	}
	else if (hour == 18)
	{
		randMax = 1500;// spike
	}
	else if (hour >= 19 && hour <= 23)
	{
		randMax = (rand() % 100) + 3;//not many
	}
	return rand() % randMax; //generates cars
}

int randHead::generateLeaving(int hour)
{	//sets number of cars that randomly leave per hour
	//set ceiling for number of cars based on time of day
	int randMax = 0;
	if (hour < 11)
	{
		randMax = hour * (rand() % 5) + 1;//not many
	}
	else if (hour == 12)
	{
		randMax = 800;//spike
	}
	else if (hour <= 17)
	{
		randMax = hour * (rand() % 50) + 1;//good number
	}
	else if (hour == 18)
	{
		randMax = 200;// not many
	}
	else if (hour < 22)
	{
		randMax = 2400;//empties out
	}
	else if (hour <= 2)
	{
		randMax = 5500;//empties out
	}
	return  (rand() % (randMax+ 1)) ; //generates leaving cars
}

int randHead::leavingLot()
{
	return ((rand() % 8 ) + 1);
}

int randHead::distributeCars()
{	//returns entrance enum equivilant
	
	lot = (rand() % 100) + 1;
	if (lot <= 25)
		return 9; //sherman A
	else if (lot <= 50)
		return 10;//sherman B
	else if (lot <= 60)
		return 11;//armory
	else if (lot <= 90)
		return 12; //tilden A
	else
		return 13; //tilden B
}

/*int randHead::getShermanACars()
{
	return shermanA;
}

int randHead::getShermanBCars()
{
	return shermanB;
}

int randHead::getTildenACars()
{
	return tildenA;
}

int randHead::getTildenBCars()
{
	return tildenB;
}

int randHead::getArmoryCars()
{
	return armory;
}
*/