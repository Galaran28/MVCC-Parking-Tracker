#include <iostream>
#include "Lot.h"
#include "randHead.h"
#include <fstream>
#include <string>
#include <sstream>//needed to take care of istringstream line
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//void ChangeTotals(int, int, int);//function previews
//void LogChange(int, int, int, int);
void LotChooser(int, int, string);

Lot Admin(40);//create class for each lot, starting maxSize is arg
Lot Lot1(500);
Lot Lot2(600);
Lot Lot3(200);
Lot Dorm(200);
Lot Open(500);
Lot Maint(200);
Lot Overflow(300);

int main()
{
	int lot, status, time;//declare variables that are the args for ChangeTotals
	string line, sLot, sStatus, sTime;//strings for reading and eventual conversion to int

	//randHead rand;
	//rand.generateCars(); //genertates number of cars going to each entrance
	int count = 0;
	
	while (count < 10)
	{
		line = "1,1,0009";//test line, to test splitting on commas, takes input in format lot,status,time
		istringstream input(line);//create an istringstream, input, that takes the current line as an argument
		getline(input, sLot, ',');//get the lot number
		getline(input, sStatus, ',');//get the status of the car, leaving or parking (0 or 1)
		getline(input, sTime, ',');//get the time
		lot = atoi (sLot.c_str());//convert the lot string to an int
		status = atoi (sStatus.c_str());//convert the status string to an int
		time = atoi (sStatus.c_str());
		bool goodInput = false;//define a boolean value to see if the input format is good
		while (!goodInput)
		{
			goodInput = true;
			if (!(lot > 0 && lot < 9))//check if the lot number is within it's boundaries
				goodInput = false;
			if (!(status == 1 || status == 0 || status == 2))//check if the car is coming or going
				goodInput = false;
			if (!(time >= 0 && time <= 2359))//check if the time is within bounds
				goodInput = false;
		}
		if (goodInput == true)//if the input is okay, update the totals
			LotChooser(lot, status, sTime);
		++count;
	}	
}


void LotChooser(int lot, int status, string time)//a function that provides lot-specific info, like the name and which lot
	//the car is parking in, as well as status. Time is a string here for easier formatting in the log
{
	switch (lot)
	{
	case 1:
		Admin.ChangeTotals("Admin", status, time);
		break;
	case 2:
		Lot1.ChangeTotals("Lot 1", status, time);
		break;
	case 3:
		Lot2.ChangeTotals("Lot 2", status, time);
		break;
	case 4:
		Lot3.ChangeTotals("Lot 3", status, time);
		break;
	case 5:
		Dorm.ChangeTotals("Dorm", status, time);
		break;
	case 6:
		Maint.ChangeTotals("Maintenance", status, time);
		break;
	case 7:
		Overflow.ChangeTotals("Overflow", status, time);
		break;
	case 8:
		Open.ChangeTotals("Open", status, time);
		break;
	}

}







