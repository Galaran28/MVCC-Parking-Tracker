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

int randHead::getCars()
{
	randCarsPerHour = rand() % 2490 + 0000;
	cout << "cars: " << randCarsPerHour << endl;
	return randCarsPerHour;
}

/*void randHead::incrementHour()
{
	hour++;
}*/

int randHead::getHours()
{
	return hour;
}

