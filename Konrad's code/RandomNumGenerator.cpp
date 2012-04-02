#include<iostream>
#include<time.h>
#include<ctime>
#include "randHead.h"
using namespace std;

int main()
{
	randHead rand1;
	int hour = 0;
	for(int minute = 0; minute < 86400; minute++)
	{
		hour = rand1.getHours();
		int randNum = rand1.getCars();
	}
}