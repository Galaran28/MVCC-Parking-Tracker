#include <iostream>
#include "Lot.h"
#include <fstream>
#include <string>
#include <sstream>//needed to take care of istringstream line
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void ChangeTotals(int, int, int);//function previews
void LogChange(int, int, int, int);
int main()
{
	Lot Admin(40);//create class for each lot, starting maxSize is arg
	Lot Lot1(500);
	Lot Lot2(600);
	Lot Lot3(200);
	Lot Dorm(200);
	Lot Open(500);
	Lot Maint(200);
	Lot Overflow(300);
	int lot, status, time;//declare variables that are the args for ChangeTotals
	string line, sLot, sStatus, sTime;//strings for reading and eventual conversion to int
	
	//The following would need to be in a loop until we reach the end of the simulation
	line = "1,2,0009";//test line, to test splitting on commas, takes input in format lot,status,time
	istringstream input(line);//create an istringstream, input, that takes the current line as an argument
	getline(input, sLot, ',');//get the lot number
	getline(input, sStatus, ',');//get the status of the car, leaving or parking (0 or 1)
	getline(input, sTime, ',');//get the time
	lot = atoi (sLot.c_str());//convert the lot string to an int
	status = atoi (sStatus.c_str());//convert the status string to an int
	time = atoi (sTime.c_str());//convert the time string to an int
	bool goodInput = true;//define a boolean value to see if the input format is good
	while (goodInput)
	{
		if (!(lot > 0 && lot < 9))//check if the lot number is within it's boundaries
			goodInput = false;
		if (!(status == 1 || status == 0 || status == 2))//check if the car is coming or going
			goodInput = false;
		if (!(time >= 0 && time <= 2359))//check if the time is within bounds
			goodInput = false;
	}
	if (goodInput == true)//if the input is okay, update the totals
		ChangeTotals(lot, status, time);
}

void ChangeTotals(int lot, int status, int time)
/*function takes the lot number, car status, and time, changes the total cars in the lot, or calls a function to check a new lot if
the car can't find a parking spot
*/
{
	Lot Admin(40);
	Lot Lot1(500);
	Lot Lot2(600);
	Lot Lot3(200);
	Lot Dorm(200);
	Lot Open(500);
	Lot Maint(200);
	Lot Overflow(300);
	switch (lot)//case statement to decide which lot to update
	{	
	case 1:
			
			if (status == 1)//if parking
			{
				Admin.Add();//add the car initially
				if ( Admin.getCurrentSize() < Admin.getMaxSize())
					LogChange(lot, status, 1, time); //if room, the car parks, outputs to the log
				else
				{
					LogChange(lot, status, 0, time);//output if car can't find a spot to the log
					status = 0;//change status 
				}
			}
			else if (status == 0)//hopefully this will catch if the status changed
			{
				Admin.Subtract();//subtract a car from the lot
				LogChange(lot, status, 2, time);//output if car leaves
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
/* function that takes care of the log file, outputs status based on the lot and if the car parks, 
can't find a spot, or leaves*/
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
}







