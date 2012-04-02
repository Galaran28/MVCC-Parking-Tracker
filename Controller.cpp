#include <iostream>
#include "Lot.h"
#include <fstream>
#include <string>
#include <sstream>//needed to take care of istringstream line
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int ChangeTotals(int, int, int);
void LogChange(int, int, int, int);
int main()
{
	Lot Admin(40);
	Lot Lot1(500);
	Lot Lot2(600);
	Lot Lot3(200);
	Lot Dorm(200);
	Lot Open(500);
	Lot Maint(200);
	Lot Overflow(300);
	int lot, status, time;
	string line, sLot, sStatus, sTime;
	line = "1,2,0009";
	istringstream input(line);
	getline(input, sLot, ',');
	getline(input, sStatus, ',');
	getline(input, sTime, ',');
	lot = atoi (sLot.c_str());
	status = atoi (sStatus.c_str());
	time = atoi (sTime.c_str());
	bool goodInput = true;
	while (goodInput)
	{
		if (!(lot > 0 && lot < 9))
			goodInput = false;
		if (!(status == 1 || status == 0))
			goodInput = false;
		if (!(time >= 0 && time <= 2359))
			goodInput = false;
	}
	if (goodInput == true)
		ChangeTotals(lot, status, time);
}

int ChangeTotals(int lot, int status, int time)
{
	Lot Admin(40);
	Lot Lot1(500);
	Lot Lot2(600);
	Lot Lot3(200);
	Lot Dorm(200);
	Lot Open(500);
	Lot Maint(200);
	Lot Overflow(300);
	switch (lot)
	{	
	case 1:
			
			if (status == 1)
			{
				Admin.Add();
				if ( Admin.getCurrentSize() < Admin.getMaxSize())
					LogChange(lot, status, 1, time);
				else
				{
					LogChange(lot, status, 0, time);
					status = 0;
				}
			}
			else if (status == 0)
			{
				Admin.Subtract();
				LogChange(lot, status, 2, time);
			}
			break;
		case 2:
			if (status == 1)
			{
				Lot1.Add();
				if ( Lot1.getCurrentSize() < Lot1.getMaxSize())
					LogChange(lot, status, 1, time);
				else
				{
					LogChange(lot, status, 0, time);
					status = 0;
				}
			}
			else if (status == 0)
			{
				Lot1.Subtract();
				LogChange(lot, status, 2, time);
			}
			break;
		case 3:
			if (status == 1)
			{
				Lot2.Add();
				if ( Lot2.getCurrentSize() < Lot2.getMaxSize())
					LogChange(lot, status, 1, time);
				else
				{
					LogChange(lot, status, 0, time);
					status = 0;
				}
			}
			else if (status == 0)
			{
				Lot2.Subtract();
				LogChange(lot, status, 2, time);
			}
			break;
		case 4:
			if (status == 1)
			{
				Lot3.Add();
				if ( Lot3.getCurrentSize() < Lot3.getMaxSize())
					LogChange(lot, status, 1, time);
				else
				{
					LogChange(lot, status, 0, time);
					status = 0;
				}
			}
			else if (status == 0)
			{
				Lot3.Subtract();
				LogChange(lot, status, 2, time);
			}
			break;
		case 5: 
			if (status == 1)
			{
				Dorm.Add();
				if ( Dorm.getCurrentSize() < Dorm.getMaxSize())
					LogChange(lot, status, 1, time);
				else
				{
					LogChange(lot, status, 0, time);
					status = 0;
				}
			}
			else if (status == 0)
			{
				Dorm.Subtract();
				LogChange(lot, status, 2, time);
			}
			break;
		case 6: 
			if (status == 1)
			{
				Open.Add();
				if ( Open.getCurrentSize() < Open.getMaxSize())
					LogChange(lot, status, 1, time);
				else
				{
					LogChange(lot, status, 0, time);
					status = 0;
				}
			}
			else if (status == 0)
			{
				Open.Subtract();
				LogChange(lot, status, 2, time);
			}
			break;
		case 7:
			if (status == 1)
			{
				Maint.Add();
				if ( Maint.getCurrentSize() < Maint.getMaxSize())
					LogChange(lot, status, 1, time);
				else
				{
					LogChange(lot, status, 0, time);
					status = 0;
				}
			}
			else if (status == 0)
			{
				Maint.Subtract();
				LogChange(lot, status, 2, time);
			}
			break;
		case 8:
			if (status == 1)
			{
				Overflow.Add();
				if ( Overflow.getCurrentSize() < Overflow.getMaxSize())
					LogChange(lot, status, 1, time);
				else
				{
					LogChange(lot, status, 0, time);
					status = 0;
				}
			}
			else if (status == 0)
			{
				Overflow.Subtract();
				LogChange(lot, status, 2, time);
			}
			break;
	}
}

void LogChange(int lot, int status, int parks, int time)
{
	ofstream log;
	log.open ("log20122012201220122012.txt", ios::app);
	switch (lot)
	{
		case 1:
			if (status == 1)
				log << time << " :: car parks in admin lot"  << endl;
			else if (status == 0)
				log << time << " :: car leaves admin lot" << endl;
			else if (status == 2)
				log << time << " :: car can't find a parking spot" << endl;
		case 2:
			if (status == 1)
				log << time << " :: car parks in lot1"  << endl;
			else if (status == 0)
				log << time << " :: car leaves lot1" << endl;
			else if (status == 2)
				log << time << " :: car can't find a parking spot" << endl;
		case 3:
			if (status == 1)
				log << time << " :: car parks in lot2"  << endl;
			else if (status == 0)
				log << time << " :: car leaves lot2" << endl;
			else if (status == 2)
				log << time << " :: car can't find a parking spot" << endl;
		case 4:
			if (status == 1)
				log << time << " :: car parks in lot3"  << endl;
			else if (status == 0)
				log << time << " :: car leaves lot3" << endl;
			else if (status == 2)
				log << time << " :: car can't find a parking spot" << endl;
		case 5:
			if (status == 1)
				log << time << " :: car parks in Dorm lot"  << endl;
			else if (status == 0)
				log << time << " :: car leaves Dorm lot" << endl;
			else if (status == 2)
				log << time << " :: car can't find a parking spot" << endl;
		case 6:
			if (status == 1)
				log << time << " :: car parks in open lot"  << endl;
			else if (status == 0)
				log << time << " :: car leaves open lot" << endl;
			else if (status == 2)
				log << time << " :: car can't find a parking spot" << endl;
		case 7:
			if (status == 1)
				log << time << " :: car parks in maint lot"  << endl;
			else if (status == 0)
				log << time << " :: car leaves maint lot" << endl;
			else if (status == 2)
				log << time << " :: car can't find a parking spot" << endl;
		case 8:
			if (status == 1)
				log << time << " :: car parks in overflow lot"  << endl;
			else if (status == 0)
				log << time << " :: car leaves overflow lot" << endl;
			else if (status == 2)
				log << time << " :: car can't find a parking spot" << endl;
	}







