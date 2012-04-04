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
	hour = 0;
}

void randHead::getCars()
{
	randCarsPerHour = rand() % 2490 + 0000;
	shermanA = (randCarsPerHour * .25);
	shermanB = (randCarsPerHour * .25);
	tildenA = (randCarsPerHour * .30);
	armory = (randCarsPerHour * .10);
	tildenB = (randCarsPerHour * .10);
}

int randHead::getShermanACars();
{
	return shermanA;
}

int randHead::getShermanBCars();
{
	return shermanB;
}

int randHead::getTildenACars();
{
	return tildenA;
}

int randHead::getTildenBCars();
{
	return tildenB;
}

int randHead::getArmoryCars();
{
	return armory;
}