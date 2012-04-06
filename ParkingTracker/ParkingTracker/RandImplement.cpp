#include "randHead.h"
#include "stdlib.h"
#include<time.h>
#include<ctime>
#include<iostream>
using namespace std;

randHead::randHead()
{
	srand(time(NULL));
	randCarsPerHour = rand() % 2490 + 0000;
}

/*void randHead::generateCars(int hour)
{
	//set celling for number of cars based on time of day
	int randMax;
	if (hour >= 0 && hour <= 8)
	{
		randMax = hour * (rand() % 100) + 3;// not many cars
	}
	else if (hour == 9)
	{
		randMax = 1500; //spike of cars
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
		randMax = hour * (rand() % 150) + 3;//not many
	}
	randCarsPerHour = rand() % randMax + 0000; //generates cars
	//adjusts cars to various entrances based on percentages
	shermanA = (randCarsPerHour * .25);
	shermanB = (randCarsPerHour * .25);
	tildenA = (randCarsPerHour * .30);
	armory = (randCarsPerHour * .10);
	tildenB = (randCarsPerHour * .10);
}*/

int randHead::getShermanACars()
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